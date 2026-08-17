#include <HijelHID_BLEKeyboard.h>

#define swPin 3 //3:ConnectorA 4:ConnectorB

HijelHID_BLEKeyboard bleKeyboard("ESP32 Keyboard");

void setup() {
  pinMode(swPin, INPUT);

  bleKeyboard.begin();
}

void loop() {
  if (bleKeyboard.isPaired()) {
    if (digitalRead(swPin) == HIGH) {
      bleKeyboard.print("hello");
      delay(200);
    }
  }
}