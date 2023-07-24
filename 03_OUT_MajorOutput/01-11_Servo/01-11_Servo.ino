#include <ESP32Servo.h>

#define moterPin 26
Servo myservo;
void setup() {
 myservo.attach(moterPin,700,2300);
 Serial.begin(115200);
 
}
void loop() {
 //時計回り(when 1450～700 µsec)　逆時計回り(when 1550～2300 µsec)　1500に近い方が回転がおそくなる
  myservo.write(1350);
  delay(5000);
  
  myservo.write(1600);
  delay(5000);
}
