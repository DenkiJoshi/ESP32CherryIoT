#define swPin 33
#define on HIGH
#define off LOW

int swState = 0;
int swFlag = 0;

void setup() {
  Serial.begin(115200);
  pinMode(swPin, INPUT_PULLUP);
}

void loop() {
  swState = digitalRead(swPin);
  if (swState == on) {
    swFlag = !swFlag;
  }

  if(swFlag == 1){
    Serial.println("押されています");
    delay(1000);
  } else {
    Serial.println("押されていません");
    delay(1000);
  }
}
