#define ledPin 26
#define swPin 32
#define on HIGH
#define off LOW

int swState = 0;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  pinMode(swPin, INPUT);
}

void loop() {
  swState = digitalRead(swPin);
  if (swState == on) {
    digitalWrite(ledPin, on); 
    Serial.println("押されています");
    delay(1000);
  } else {
    digitalWrite(ledPin, off);
    Serial.println("押されていません");
    delay(1000);
  }
}
