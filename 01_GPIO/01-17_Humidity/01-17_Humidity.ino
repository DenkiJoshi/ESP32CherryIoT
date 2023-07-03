#include <DHT.h>              // ライブラリのインクルード
 
#define DHT_PIN 33            // DHT11のDATAピンをデジタルピン19に定義
#define DHT_MODEL DHT11       // 接続するセンサの型番を定義する(DHT11やDHT22など)
 
 DHT dht(DHT_PIN, DHT_MODEL);  // センサーの初期化
 
 
 
 void setup() {
 
   Serial.begin(115200);         // シリアル通信の開始
   dht.begin();                // センサーの動作開始
  
}
 
 
 void loop(){
 
   delay(2000);                // センサーの読み取りを2秒間隔に
 
   float Humidity = dht.readHumidity();          // 湿度の読み取り
   float Temperature = dht.readTemperature();    // 温度の読み取り(摂氏)
 
   if (isnan(Humidity) || isnan(Temperature)) {  // 読み取りのチェック
     Serial.println("ERROR");
     return;
   }
 
// シリアルモニタに温度&湿度を表示  
   Serial.print("温度: ");
   Serial.print(Temperature);
   Serial.print("[℃]");
 
   Serial.print("  湿度: "); 
   Serial.print(Humidity);  
   Serial.println("[%]");
 
}
