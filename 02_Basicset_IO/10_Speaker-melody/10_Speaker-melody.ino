const int spkrPin = 3; //3:ConnectorA 4:ConnectorB

#define BEAT 230
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

void doremi(){
  ledcWriteTone(spkrPin, DO);
  delay(250);
  ledcWriteTone(spkrPin, RE);
  delay(250);
  ledcWriteTone(spkrPin, MI);
  delay(250);
  ledcWriteTone(spkrPin, FA);
  delay(250);
  ledcWriteTone(spkrPin, SO);
  delay(250);
  ledcWriteTone(spkrPin, RA);
  delay(250);
  ledcWriteTone(spkrPin, TI);
  delay(250);
  ledcWriteTone(spkrPin, octDO);
  delay(250);
  ledcWriteTone(spkrPin, 0); // no sound
  delay(250);
}

void melodychime(){
  ledcWriteTone(spkrPin, RA);
  delay(BEAT);
  ledcWriteTone(spkrPin, FA);
  delay(BEAT);  
  ledcWriteTone(spkrPin, DO);
  delay(BEAT);
  ledcWriteTone(spkrPin, FA);
  delay(BEAT);
  ledcWriteTone(spkrPin, SO);
  delay(BEAT);
  ledcWriteTone(spkrPin, octDO);
  delay(BEAT * 2);  
  ledcWriteTone(spkrPin, DO);
  delay(BEAT);  
  ledcWriteTone(spkrPin, SO);
  delay(BEAT);
  ledcWriteTone(spkrPin, RA);
  delay(BEAT);  
  ledcWriteTone(spkrPin, SO);
  delay(BEAT);  
  ledcWriteTone(spkrPin, DO);
  delay(BEAT);
  ledcWriteTone(spkrPin, FA);
  delay(BEAT * 3);
  ledcWriteTone(spkrPin, 0);
  delay(BEAT);
}

void fryer(){
  ledcWriteTone(spkrPin, SO);
  delay(BEAT);
  ledcWriteTone(spkrPin, FA);
  delay(BEAT);  
  ledcWriteTone(spkrPin, SO);
  delay(BEAT);
  ledcWriteTone(spkrPin, 0);
  delay(BEAT);
  ledcWriteTone(spkrPin, SO);
  delay(BEAT);
  ledcWriteTone(spkrPin, FA);
  delay(BEAT);  
  ledcWriteTone(spkrPin, SO);
  delay(BEAT);  
  ledcWriteTone(spkrPin, 0);
  delay(BEAT);
  ledcWriteTone(spkrPin, SO);
  delay(BEAT);  
  ledcWriteTone(spkrPin, FA);
  delay(BEAT);  
  ledcWriteTone(spkrPin, SO);
  delay(BEAT);
  ledcWriteTone(spkrPin, 0);
  delay(BEAT);
  ledcWriteTone(spkrPin, SO);
  delay(BEAT);  
  ledcWriteTone(spkrPin, FA);
  delay(BEAT);  
  ledcWriteTone(spkrPin, SO);
  delay(BEAT);
  ledcWriteTone(spkrPin, 0);
  delay(BEAT);
}

void setup() {
  pinMode(spkrPin, OUTPUT);
  ledcAttach(spkrPin, 12000, 8); //Pin setting(Pin num, Max frequency, Resolution)
}

void loop() {
  doremi();
  melodychime();
  fryer();
}
