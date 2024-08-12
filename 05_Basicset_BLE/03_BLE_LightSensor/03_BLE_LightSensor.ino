#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

const int litsnsrPin = 3; //3:ConnectorA 4:ConnectorB

BLEServer* pServer = NULL;
BLEService* pService = NULL;
BLECharacteristic* pCharacteristic = NULL;

// The UUID of the service and characteristic you want to advertise
// https://github.com/NordicSemiconductor/bluetooth-numbers-database/tree/master/v1
#define SERVICE_UUID        "0000181a-0000-1000-8000-00805f9b34fb" // org.bluetooth.service.environmental_sensing
#define CHARACTERISTIC_UUID "00002A59-0000-1000-8000-00805f9b34fb" // org.bluetooth.characteristic.analog_output

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  pinMode(litsnsrPin, INPUT);

  // Initialize the BLE device
  BLEDevice::init("My BLE Device");

  // Create the BLE Server
  pServer = BLEDevice::createServer();

  // Create the BLE Service
  pService = pServer->createService(SERVICE_UUID);

  // Create a BLE Characteristic
  pCharacteristic = pService->createCharacteristic(
                      CHARACTERISTIC_UUID,
                      BLECharacteristic::PROPERTY_READ   |
                      BLECharacteristic::PROPERTY_WRITE  |
                      BLECharacteristic::PROPERTY_NOTIFY |
                      BLECharacteristic::PROPERTY_INDICATE
                    );

  // Create a BLE Descriptor
  pCharacteristic->addDescriptor(new BLE2902());

  // Start the service
  pService->start();

  // Start advertising
  BLEAdvertising* pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(true);
  pAdvertising->setMinPreferred(0x06);  // functions that help with iPhone connections issue
  pAdvertising->setMinPreferred(0x12);
  BLEDevice::startAdvertising();
  Serial.println("Characteristic defined! Now you can read it in your phone!");
}

void loop() {
  float litsnsr_ad = analogRead(litsnsrPin); // Read analog data
  float litsnsr_v = litsnsr_ad * 3.3 / 4096; // Calculation of voltage value
  float lux = 10000 * litsnsr_v / (3.3 - litsnsr_v) / 1000; // Calculation of lux value

  //Look at the serial monitor
  Serial.println(" Lux : " + String(lux));

  pCharacteristic->setValue(String(lux) + "lux");

  pCharacteristic->notify(); // Notify to client
  delay(500);
}