const int motorPin = 4;
//4:ConnectorA 9:ConnectorB

void setup() {
  pinMode(motorPin, OUTPUT);
}

void loop() {
  digitalWrite(motorPin, HIGH);
  delay(1000);
  digitalWrite(motorPin, LOW);
  delay(3000);
}
