#define buzzerPin 26 //OUTPUTA:26 OUTPUTB:13
#define BEAT 500 //音を鳴らす時間

//音階名と周波数の対応
#define DO 261.6
#define _DO 277.18
#define RE 293.665
#define _RE 311.127
#define MI 329.63
#define FA 349.228
#define _FA 369.994
#define SO 391.995
#define _SO 415.305
#define RA 440
#define _RA 466.164
#define SI 493.883
#define octDO 523.251

void playmusic(){
    ledcWriteTone(1,DO);
    delay(BEAT);
    ledcWriteTone(1,RE);
    delay(BEAT);
    ledcWriteTone(1,MI);
    delay(BEAT);
    ledcWriteTone(1,FA);
    delay(BEAT);
    ledcWriteTone(1,SO);
    delay(BEAT);
    ledcWriteTone(1,RA);
    delay(BEAT);
    ledcWriteTone(1,SI);
    delay(BEAT);
    ledcWriteTone(1,octDO);
    delay(BEAT);
    ledcWriteTone(1,0);
    delay(BEAT);
}
void setup() {
  ledcSetup(1,12000, 8);
  ledcAttachPin(buzzerPin,1);
}

void loop() {
  playmusic();
}
