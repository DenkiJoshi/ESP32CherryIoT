#define ledPin 26
#define on HIGH
#define off LOW

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, on); 
  delay(1000);
  digitalWrite(ledPin, off);
  delay(1000);
}