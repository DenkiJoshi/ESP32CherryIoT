//ツール→シリアルプロッタで波形を見てください。

#define SoundSensor 33 //INA:33 INB:15
int SoundValue ;

void setup () {
  Serial.begin (115200);
  pinMode (SoundSensor, INPUT);
}
void loop () {
  SoundValue=analogRead(SoundSensor);
  Serial.println(SoundValue);
  delay(10);
}
