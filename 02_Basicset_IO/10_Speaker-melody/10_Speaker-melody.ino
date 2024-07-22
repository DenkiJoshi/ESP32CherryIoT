const int spkrPin = 4;
//4:ConnectorA 9:ConnectorB

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
    ledcWriteTone(0, DO); //PWM output(channel, frequency)
    delay(BEAT * 2);
    ledcWriteTone(0, RE);
    delay(BEAT * 2);
    ledcWriteTone(0, MI);
    delay(BEAT * 2);
    ledcWriteTone(0, FA);
    delay(BEAT * 2);
    ledcWriteTone(0, SO);
    delay(BEAT * 2);
    ledcWriteTone(0, RA);
    delay(BEAT * 2);
    ledcWriteTone(0, TI);
    delay(BEAT * 2);
    ledcWriteTone(0, octDO);
    delay(BEAT);
    ledcWriteTone(0, 0); // no sound
    delay(BEAT);
}

void melodychime(){
  ledcWriteTone(0, RA);
    delay(BEAT);
  ledcWriteTone(0, FA);
    delay(BEAT);  
  ledcWriteTone(0, DO);
    delay(BEAT);
  ledcWriteTone(0, FA);
    delay(BEAT);
  ledcWriteTone(0, SO);
    delay(BEAT);
  ledcWriteTone(0, octDO);
    delay(BEAT * 2);  
  ledcWriteTone(0, DO);
    delay(BEAT);  
  ledcWriteTone(0, SO);
    delay(BEAT);
  ledcWriteTone(0, RA);
    delay(BEAT);  
  ledcWriteTone(0, SO);
    delay(BEAT);  
  ledcWriteTone(0, DO);
    delay(BEAT);
  ledcWriteTone(0, FA);
    delay(BEAT * 3);
  ledcWriteTone(0, 0);
    delay(BEAT);
}

void fryer(){
  ledcWriteTone(0, SO);
    delay(BEAT);
  ledcWriteTone(0, FA);
    delay(BEAT);  
  ledcWriteTone(0, SO);
    delay(BEAT);
  ledcWriteTone(0, 0);
    delay(BEAT);
  ledcWriteTone(0, SO);
    delay(BEAT);
  ledcWriteTone(0, FA);
    delay(BEAT);  
  ledcWriteTone(0, SO);
    delay(BEAT);  
  ledcWriteTone(0, 0);
    delay(BEAT);
  ledcWriteTone(0, SO);
    delay(BEAT);  
  ledcWriteTone(0, FA);
    delay(BEAT);  
  ledcWriteTone(0, SO);
    delay(BEAT);
  ledcWriteTone(0, 0);
    delay(BEAT);
  ledcWriteTone(0, SO);
    delay(BEAT);  
  ledcWriteTone(0, FA);
    delay(BEAT);  
  ledcWriteTone(0, SO);
    delay(BEAT);
  ledcWriteTone(0, 0);
    delay(BEAT);
}

void setup() {
  ledcSetup(0, 12000, 8); //PWM outputs setting.(channel, frequency, duty ratio)
  ledcAttachPin(spkrPin, 0); //Pin setting(pin num, channel)
}

void loop() {
  doremi();
  melodychime();
  fryer();
}
