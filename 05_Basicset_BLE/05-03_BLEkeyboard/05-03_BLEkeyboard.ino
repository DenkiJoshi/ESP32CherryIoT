//https://www.hobbyhappyblog.jp/esp32-lolind32-bluetooth-keyboard

#include <BleKeyboard.h>
#define swPin 32
#define on HIGH
#define off LOW

BleKeyboard bleKeyboard("hobbyhappy"); // Can be renamed to any device name you like.

void setup() {
  bleKeyboard.begin();
  pinMode(25,INPUT_PULLUP);
}

void loop() {
  if(bleKeyboard.isConnected()) {     // Check to see if they are connected.
    if(digitalRead(swPin) == on){       // If GPIO16 change to LOW
      bleKeyboard.print("hobby");     // Send hobby
      delay(200);
    }
  }
}
