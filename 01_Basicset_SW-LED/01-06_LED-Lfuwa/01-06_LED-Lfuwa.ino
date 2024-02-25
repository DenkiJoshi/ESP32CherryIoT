//Connect LED to "OUT" connector.
//Slide switch to 3.3V.

#define ledPin 25

void setup() {
  ledcSetup(0, 12800, 8); // ledcSetup(channel, frequency, number of bits)
  ledcAttachPin(ledPin, 0); // Connect ledPin to channel 0
}

void loop() {
  int i = 0;
  for (i=0; i<=255; i++){ // Increase the value of i from 0 to 255
   ledcWrite(0, i);
   delay(10); // Change speed
  }
  for (i=255; i>=0; i--){ // Decrease the value of i from 255 to 0
   ledcWrite(0, i);
   delay(10); // Change speed
  }
}