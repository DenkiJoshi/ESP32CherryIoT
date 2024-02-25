//Connect DCMotor(Mini Fan) to "OUT" connector.
//Slide switch to 5.0V.

#define motorPin 25

void setup() {
  pinMode(motorPin, OUTPUT);
}

void loop() {
  digitalWrite(motorPin, HIGH);
  delay(1000);
  digitalWrite(motorPin, LOW);
  delay(3000);
}
