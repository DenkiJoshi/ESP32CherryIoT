#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#include <esp_task_wdt.h>

const int ledPin = 13; // LEDの接続ピン

bool bleOn = false;

BLEServer* pServer = NULL;
BLEService* pService = NULL;
BLECharacteristic* pCharacteristic = NULL;

// サービスとキャラクタリスティックのUUID
#define SERVICE_UUID        "0000181a-0000-1000-8000-00805f9b34fb" // org.bluetooth.service.environmental_sensing
#define CHARACTERISTIC_UUID "00002A56-0000-1000-8000-00805f9b34fb" // org.bluetooth.characteristic.digital

class MyCallbacks : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *pCharacteristic) {
    String rxValue = pCharacteristic->getValue().c_str();
    if (rxValue.equals("ON")) {
      bleOn = true;
    } else if (rxValue.equals("OFF")) {
      bleOn = false;
    }
    Serial.print("Received Value: ");
    Serial.println(rxValue);
  }
};

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE work!");

  // ウォッチドッグタイマーを無効にする
  disableCore0WDT();

  pinMode(ledPin, OUTPUT); // LEDピンを出力に設定
  digitalWrite(ledPin, LOW); // 初期状態でLEDをOFF

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
                      BLECharacteristic::PROPERTY_WRITE
                    );

  // Set the characteristic's callback
  pCharacteristic->setCallbacks(new MyCallbacks());

  // Start the service
  pService->start();

  // Start advertising
  BLEAdvertising* pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(true);
  pAdvertising->start();
  Serial.println("Advertising Started");
}

void loop() {
  digitalWrite(ledPin, bleOn ? HIGH : LOW);
  delay(500);
}
