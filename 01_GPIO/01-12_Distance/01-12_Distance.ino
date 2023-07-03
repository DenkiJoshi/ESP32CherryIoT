// 超音波センサを使って距離を表示するプログラム

#define echoPin 33 //INPUTA:33 INPUTB:32
#define trigPin 17 //INPUTA:17 INPUTB:19

#define LEDPin 13 //OUTPUTA:26 OUTPUTB:13

#define on LOW
#define off HIGH

double Duration = 0; //受信した間隔
double Distance = 0; //距離

void setup() {
  Serial.begin(115200);
  pinMode(echoPin,INPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(LEDPin,OUTPUT);
}

void loop() {
  digitalWrite(LEDPin, off);
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); //超音波を出力
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  Duration = pulseIn(echoPin, HIGH); //センサからの入力

  if (Duration > 0) {
    Duration = Duration/2; //往復距離を半分
    Distance = Duration*340*100/1000000; //音速を340m/sに設定 
    Serial.print("Distance:");
    Serial.print(Distance);
    Serial.println("cm");
  }
  
  if (Distance < 10) {
    digitalWrite(LEDPin, on);
    delay(50);
    digitalWrite(LEDPin, off);
    delay(50);
  }
  else {
    digitalWrite(LEDPin, off);
  }

  delay(500);

}
