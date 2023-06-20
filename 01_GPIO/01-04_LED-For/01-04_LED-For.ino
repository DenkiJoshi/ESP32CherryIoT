#define ledPin 25
#define on HIGH
#define off LOW

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  for(int i = 0; i < 3; i++){
    digitalWrite(ledPin, on); 
    delay(500);
    digitalWrite(ledPin, off);
    delay(500);
  }
  delay(2000);
}
