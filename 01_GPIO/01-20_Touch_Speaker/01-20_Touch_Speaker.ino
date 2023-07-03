const int SENSOR = 33; //INA33 INB32

#define BUZZER_PIN 26 //OUTPUTA:26 OUTPUTB:13
//音を鳴らす時間
#define BEAT 250
//音階名と周波数の対応
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
  pinMode(SENSOR, INPUT);
  Serial.begin(115200);
  ledcSetup(1,12000, 8);
  ledcAttachPin(BUZZER_PIN,1);
}

void loop() {
    
  if (digitalRead(SENSOR)==HIGH) {
    Serial.println("Touch!");
    playmusic();
  } else {
    Serial.println("...");
  }
  delay(500);
}
