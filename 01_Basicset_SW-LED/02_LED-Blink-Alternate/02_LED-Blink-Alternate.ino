const int ledPin1 = 4;
const int ledPin2 = 10;
//4:ConnectorA 9:ConnectorB 10:Builtin

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
  digitalWrite(ledPin1, HIGH); //ON
  digitalWrite(ledPin2, LOW); //OFF
  delay(500); //0.5msec
  digitalWrite(ledPin1, LOW); //OFF
  digitalWrite(ledPin2, HIGH); //ON
  delay(500); //0.5msec
}
