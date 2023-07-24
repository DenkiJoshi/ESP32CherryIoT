//Connect SingleLED to OUT connector

#define ledPin 25
#define on HIGH
#define off LOW

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, on); 
  delay(500); //msec (1000msec=1sec)
  digitalWrite(ledPin, off);
  delay(500); //msec (1000msec=1sec)
}
