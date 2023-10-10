// 超音波センサを使って距離を表示するプログラム

#define echoPin 33
#define trigPin 32

double Duration = 0; //受信した間隔
double Distance = 0; //距離

void setup() {
  Serial.begin(115200);
  pinMode(echoPin,INPUT);
  pinMode(trigPin,OUTPUT);
}

void loop() { 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); //超音波を出力
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  Duration = pulseIn(echoPin, HIGH); //センサからの入力
  Duration = Duration/2; //往復距離を半分
  Distance = Duration*340*100/1000000; //音速を340m/sに設定 
  Serial.print("Distance:");
  Serial.print(Distance);
  Serial.println("cm");
  delay(500);
}
