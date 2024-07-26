const int spkrPin = 3; //3:ConnectorA 5:ConnectorB

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
#define TI 493.883
#define octDO 523.251

void playmusic(){
  ledcWriteTone(spkrPin, DO);
  delay(250);
  ledcWriteTone(spkrPin, RE);
  delay(250);
  ledcWriteTone(spkrPin, MI);
  delay(250);
  ledcWriteTone(spkrPin, 0); // no sound
  delay(250);
}

void setup() {
  pinMode(spkrPin, OUTPUT);
  ledcAttach(spkrPin, 12000, 8); //Pin setting(Pin num, Max frequency, Resolution)
}

void loop() {
  playmusic();
  delay(3000);
}
