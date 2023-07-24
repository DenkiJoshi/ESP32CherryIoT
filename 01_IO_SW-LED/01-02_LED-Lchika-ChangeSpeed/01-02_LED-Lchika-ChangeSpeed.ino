//Connect SingleLED to OUT connector

#define ledPin 25
#define on HIGH
#define off LOW

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, on); 
  delay(100); //msec (1000msec=1sec)
  digitalWrite(ledPin, off);
  delay(100); //msec (1000msec=1sec)
  digitalWrite(ledPin, on); 
  delay(100); //msec (1000msec=1sec)
  digitalWrite(ledPin, off);
  delay(100); //msec (1000msec=1sec)
  digitalWrite(ledPin, on); 
  delay(1000); //msec (1000msec=1sec)
  digitalWrite(ledPin, off);
  delay(1000); //msec (1000msec=1sec)
}
