//Connect Vibration to "OUT" connector.
//Slide switch to 3.3V.

#define vibPin 25

void setup() {
  pinMode(vibPin, OUTPUT);
}

void loop() {
  digitalWrite(vibPin, HIGH);
  delay(1000);
  digitalWrite(vibPin, LOW);
  delay(1000);
}
