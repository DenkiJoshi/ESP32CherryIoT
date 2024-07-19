const int ledPin = 0;
//0:ConnectorA 4:ConnectorB 10:Builtin

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  for (int i=0; i<=255; i++){ //Increase brightness
   analogWrite(ledPin, i);
   delay(10); // Change speed
  }
  for (int i=255; i>=0; i--){ //Decrease brightness
   analogWrite(ledPin, i);
   delay(10); // Change speed
  }
}