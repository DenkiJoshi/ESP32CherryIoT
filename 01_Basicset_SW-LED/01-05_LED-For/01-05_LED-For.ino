//Connect LED to "OUT" connector.
//Slide switch to 3.3V.

#define ledPin 25

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  for(int i = 0; i < 3; i++){
    digitalWrite(ledPin, HIGH); //LED on
    delay(500);
    digitalWrite(ledPin, LOW); //LED off
    delay(500);
  }
  delay(2000);
}
