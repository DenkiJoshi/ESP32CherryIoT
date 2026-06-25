#include <ESP32Servo.h> //ESP32Servo by Kevin Harrington

const int motorPin = 3; //3:ConnectorA 4:ConnectorB

Servo myservo;

void setup() {
  myservo.attach(motorPin,700,2300);
}

void loop() {
  //Clockwise(when 1450～700 µsec)　Counter-clockwise(when 1550～2300 µsec)
  //The rotation speed becomes slower the closer it is to 1500.
  myservo.write(1350);
  delay(5000);
  
  myservo.write(1600);
  delay(5000);     
}
