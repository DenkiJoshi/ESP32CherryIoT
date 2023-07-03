#define spPIN 26
//音を鳴らす時間
#define BEAT 500
//音階名と周波数の対応
#define C4 261.6
#define C_4 277.18
#define D4 293.665
#define D_4 311.127
#define E4 329.63
#define F4 349.228
#define F_4 369.994
#define G4 391.995
#define G_4 415.305
#define A4 440
#define A_4 466.164
#define B4 493.883
#define C5 523.251

void playmusic(){
    ledcWriteTone(1,C4);
    delay(BEAT);
    ledcWriteTone(1,D4);
    delay(BEAT);
    ledcWriteTone(1,E4);
    delay(BEAT);
    ledcWriteTone(1,F4);
    delay(BEAT);
    ledcWriteTone(1,G4);
    delay(BEAT);
    ledcWriteTone(1,A4);
    delay(BEAT);
    ledcWriteTone(1,B4);
    delay(BEAT);
    ledcWriteTone(1,C5);
    delay(BEAT);
    ledcWriteTone(1,0);
    delay(BEAT);
}
void setup() {
  ledcSetup(1,12000, 8);
  ledcAttachPin(spPIN,1);
}

void loop() {
  playmusic();
}
