#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

BLEServer* pServer = NULL;
BLECharacteristic* pCharacteristic = NULL;
bool deviceConnected = false;
bool oldDeviceConnected = false;
uint8_t value = 0;

#define SERVICE_UUID        "0000181a-0000-1000-8000-00805f9b34fb" // org.bluetooth.service.environmental_sensing 
#define CHARACTERISTIC_UUID "00002a59-0000-1000-8000-00805f9b34fb" // org.bluetooth.characteristic.analog_output
//#define CHARACTERISTIC_UUID "00002a57-0000-1000-8000-00805f9b34fb" // org.bluetooth.characteristic.digital_output

#define cdsPin 33

class MyServerCallbacks: public BLEServerCallbacks {
    void onConnect(BLEServer* pServer) {
      deviceConnected = true;
    };

    void onDisconnect(BLEServer* pServer) {
      deviceConnected = false;
    }
};

void setup() {
  Serial.begin(9600);
  pinMode(cdsPin, INPUT);

  // Create the BLE Device
  BLEDevice::init("SchooMy_IoT_hamako");

  // Create the BLE Server
  pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  // Create the BLE Service
  BLEService *pService = pServer->createService(SERVICE_UUID);

  // Create a BLE Characteristic
  pCharacteristic = pService->createCharacteristic(
                      CHARACTERISTIC_UUID,
                      BLECharacteristic::PROPERTY_READ   |
                      BLECharacteristic::PROPERTY_WRITE  |
                      BLECharacteristic::PROPERTY_NOTIFY |
                      BLECharacteristic::PROPERTY_INDICATE
                    );

  // https://www.bluetooth.com/specifications/gatt/viewer?attributeXmlFile=org.bluetooth.descriptor.gatt.client_characteristic_configuration.xml
  // Create a BLE Descriptor
  pCharacteristic->addDescriptor(new BLE2902());

  // Start the service
  pService->start();

  // Start advertising
  pServer->getAdvertising()->start();
  Serial.println("Waiting a client connection to notify...");
}

void loop() {
  // R1のAD値を取得
  float cds_ad = analogRead(cdsPin);

  // AD値を電圧値に変換
  float cds_v = cds_ad * 3.3 / 4096;

  // 電圧値より、Lux計算
  float lux = 10000 * cds_v / (3.3 - cds_v) / 1000;

  Serial.print(lux);
  Serial.println(" Lux ");
    
  value = (int16_t)lux;
  
  if (deviceConnected) {
    Serial.printf("*** NOTIFY: %d ***\n", value);

    pCharacteristic->setValue(&value, 1);
    pCharacteristic->notify();
    //pCharacteristic->indicate();
  }
  delay(2000);

}
