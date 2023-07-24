//Connect PushSwitch to IN connector
//Connect SingleLED to OUT connector

#define ledPin 25
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
    delay(200);
  } else {
    digitalWrite(ledPin, off);
    Serial.println("押されていません");
    delay(200);
  }
}
