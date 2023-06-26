#define motorPin 25
#define on HIGH
#define off LOW

void setup() {
  pinMode(motorPin, OUTPUT);
}

void loop() {
  digitalWrite(motorPin, on); 
  delay(1000);
  digitalWrite(motorPin, off);
  delay(3000);
}
