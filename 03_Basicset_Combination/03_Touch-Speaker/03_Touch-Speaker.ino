const int touchPin = 3; //3:ConnectorA 4:ConnectorB
const int spkrPin = 4; //3:ConnectorA 4:ConnectorB

#define C4 806.964
#define D4 718.923

void playmusic(){
  ledcWriteTone(spkrPin,C4);
  delay(230);
  ledcWriteTone(spkrPin,0);
  ledcWriteTone(spkrPin,D4);
  delay(230);
  ledcWriteTone(spkrPin,0);
  ledcWriteTone(spkrPin,C4);
  delay(250);
  ledcWriteTone(spkrPin,0);
  delay(200);
  ledcWriteTone(spkrPin,C4);
  delay(230);
  ledcWriteTone(spkrPin,0);
  ledcWriteTone(spkrPin,D4);
  delay(230);
  ledcWriteTone(spkrPin,0);
  ledcWriteTone(spkrPin,C4);
  delay(250);
  ledcWriteTone(spkrPin,0);
  delay(200);
  ledcWriteTone(spkrPin,C4);
  delay(230);
  ledcWriteTone(spkrPin,0);
  ledcWriteTone(spkrPin,D4);
  delay(230);
  ledcWriteTone(spkrPin,0);
  ledcWriteTone(spkrPin,C4);
  delay(230);
  ledcWriteTone(spkrPin,0);
}

void setup() {
  Serial.begin(115200);
  pinMode(touchPin, INPUT);
  pinMode(spkrPin, OUTPUT);
  ledcAttach(spkrPin, 12000, 8); //Pin setting(Pin num, Max frequency, Resolution)
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
