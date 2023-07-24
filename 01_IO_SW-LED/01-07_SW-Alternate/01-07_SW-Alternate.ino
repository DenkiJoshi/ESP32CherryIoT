//Connect PushSwitch to IN connector

#define swPin 32
#define on HIGH
#define off LOW

int swState = 0;
int swFlag = 0;

void setup() {
  Serial.begin(115200);
  pinMode(swPin, INPUT);
}

void loop() {
  swState = digitalRead(swPin);
  if (swState == on) {
    swFlag = !swFlag;
  }

  if(swFlag == 1){
    Serial.println("ON");
    delay(500);
  } else {
    Serial.println("OFF");
    delay(500);
  }
}
