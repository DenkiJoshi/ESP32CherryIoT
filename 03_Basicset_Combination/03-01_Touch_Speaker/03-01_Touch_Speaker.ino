//Connect Touch Sensor to "IN" connector.
//Connect Speaker to "OUT" connector.
//Slide switch to 3.3V.

#define touchPin 32
#define spPIN 25

#define BEAT 250
#define C4 806.964
#define D4 718.923

void playmusic(){
    ledcWriteTone(1,C4);
    delay(BEAT);
    ledcWriteTone(1,0);
    ledcWriteTone(1,D4);
    delay(BEAT);
    ledcWriteTone(1,0);
    ledcWriteTone(1,C4);
    delay(250);
    ledcWriteTone(1,0);
    delay(200);
    ledcWriteTone(1,C4);
    delay(BEAT);
    ledcWriteTone(1,0);
    ledcWriteTone(1,D4);
    delay(BEAT);
    ledcWriteTone(1,0);
    ledcWriteTone(1,C4);
    delay(250);
    ledcWriteTone(1,0);
    delay(200);
    ledcWriteTone(1,C4);
    delay(BEAT);
    ledcWriteTone(1,0);
    ledcWriteTone(1,D4);
    delay(BEAT);
    ledcWriteTone(1,0);
    ledcWriteTone(1,C4);
    delay(BEAT);
    ledcWriteTone(1,0);
}

void setup() {
  Serial.begin(115200);
  pinMode(touchPin, INPUT);
  ledcSetup(1,12000, 8);
  ledcAttachPin(spPIN,1);
}

void loop() {
  if (digitalRead(touchPin)==HIGH) {
    Serial.println("Touch!");
    playmusic();
  } else {
    Serial.println("...");
  }
  delay(500);
}
