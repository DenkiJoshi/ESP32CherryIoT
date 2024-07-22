const int spkrPin = 32;
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
    ledcWriteTone(4, DO); //PWM output(channel, frequency)
    delay(BEAT * 2);
    ledcWriteTone(4, RE);
    delay(BEAT * 2);
    ledcWriteTone(4, MI);
    delay(BEAT * 2);
    ledcWriteTone(4, 0); // no sound
    delay(BEAT);
}

void setup() {
  ledcAttachChannel(spkrPin, 100, 14, 0); //Pin setting(pin num, frequency, resolution, channel)
}

void loop() {
  doremi();
  ledcAttach(spkrPin,NOTE_A,7);
  delay(500);
}
