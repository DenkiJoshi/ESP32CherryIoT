//Connect Touch sensor to "IN" connector.
//Slide switch to 3.3V.
//After writing the program, check the serial monitor.

#define touchPin 32

void setup() {
  Serial.begin(115200);
  pinMode(touchPin, INPUT);
}

void loop() {
  if (digitalRead(touchPin)==HIGH) {
    Serial.println("Touch!");
  } else {
    Serial.println("...");
  }
  delay(500);
}