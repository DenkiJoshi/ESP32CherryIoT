const int ledPin = 0; //Connect LED to GPIO0

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  for (int i=0; i<=255; i++){ //Increase brightness
   analogWrite(ledPin, i);
   delay(10); // Change speed
  }
  for (i=255; i>=0; i--){ //Decrease brightness
   analogWrite(ledPin, i);
   delay(10); // Change speed
  }
}