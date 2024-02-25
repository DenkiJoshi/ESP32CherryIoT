//Connect LED to "OUT" connector.
//Slide switch to 3.3V.

#define ledPin 25

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH); //LED on
  delay(100); //msec (1000msec=1sec)
  digitalWrite(ledPin, LOW); //LED off
  delay(100); //msec (1000msec=1sec)
  digitalWrite(ledPin, HIGH); 
  delay(100); //msec (1000msec=1sec)
  digitalWrite(ledPin, LOW);
  delay(100); //msec (1000msec=1sec)
  digitalWrite(ledPin, HIGH); 
  delay(1000); //msec (1000msec=1sec)
  digitalWrite(ledPin, LOW);
  delay(1000); //msec (1000msec=1sec)
}