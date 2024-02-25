//Connect Photo Electric Counter to "IN" connector.
//Slide switch to 3.3V.
//After writing the program, check the serial monitor.

#define ruptPin 32

void setup(){
  pinMode(ruptPin, INPUT);
  Serial.begin(115200);
}

void loop(){
  if (digitalRead(ruptPin)==HIGH) {
    Serial.println("Interrupt!");
  } else {
    Serial.println("...");
  }
  delay(500);
}
