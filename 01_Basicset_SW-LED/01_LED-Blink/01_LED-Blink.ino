const int ledPin = 0; //Connect LED to GPIO0

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH); //ON
  delay(500); //0.5msec
  digitalWrite(ledPin, LOW); //OFF
  delay(500); //0.5msec
}
