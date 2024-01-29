#include <DHT20.h> // ライブラリのインクルード

DHT20 DHT(&Wire1); // センサーの初期化
 
void setup() {
  Serial.begin(115200); // シリアル通信の開始
  Wire1.begin(33, 32); // センサーの動作開始

  delay(2000); // センサー動作安定まで待つ
}

void loop(){
  delay(2000);                // センサーの読み取りを2秒間隔に

  DHT.read(); 
  float Humidity = DHT.getHumidity();          // 湿度の読み取り
  float Temperature = DHT.getTemperature();    // 温度の読み取り(摂氏)
 
  // シリアルモニタに温度&湿度を表示  
  Serial.print("温度: ");
  Serial.print(Temperature);
  Serial.print("[℃]");

  Serial.print("  ");

  Serial.print("湿度: "); 
  Serial.print(Humidity);  
  Serial.println("[%]");
}
