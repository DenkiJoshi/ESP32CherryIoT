//Connect Servo to "OUT" connector.
//Slide switch to 3.3V.

#include <ESP32Servo.h> //ESPServo by Kevin Harrington

#define moterPin 25
Servo myservo;
int angle = 0;

void setup() {
  myservo.attach(moterPin);
}

void loop() {
  for(angle = 0; angle <= 180; angle++) {   // 0-180 right                         
    myservo.write(angle);
    delay(15);
  }
  for(angle = 180; angle >= 0; angle--) {    // 180-0  left                  
    myservo.write(angle);  
    delay(15);      
  }
}
