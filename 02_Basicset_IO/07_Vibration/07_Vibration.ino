const int vibPin = 4;
//4:ConnectorA 9:ConnectorB

void setup() {
  pinMode(vibPin, OUTPUT);
}

void loop() {
  digitalWrite(vibPin, HIGH);
  delay(1000);
  digitalWrite(vibPin, LOW);
  delay(1000);
}
