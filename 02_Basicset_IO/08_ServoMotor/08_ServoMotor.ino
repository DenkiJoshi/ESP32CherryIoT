#include <ESP32Servo.h> //ESP32Servo by Kevin Harrington

const int moterPin = 4;
//4:ConnectorA 9:ConnectorB

Servo myservo;
int angle = 0;

void setup() {
  myservo.attach(moterPin);
}

void loop() {
  // 0-180 right
  for(angle = 0; angle <= 180; angle++) {                        
    myservo.write(angle);
    delay(15);
  }
  // 180-0  left 
  for(angle = 180; angle >= 0; angle--) {                 
    myservo.write(angle);  
    delay(15);      
  }
}
