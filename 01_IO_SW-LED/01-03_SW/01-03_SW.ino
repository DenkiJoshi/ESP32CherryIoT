//Connect PushSwitch to IN connector

#define swPin 32
#define on HIGH
#define off LOW

int swState = 0;

void setup() {
  Serial.begin(115200);
  pinMode(swPin, INPUT);
}

void loop() {
  swState = digitalRead(swPin);
  if (swState == on) {
    Serial.println("Pushed");
    delay(500);
  } else {
    Serial.println("Not Pushed");
    delay(500);
  }
}
