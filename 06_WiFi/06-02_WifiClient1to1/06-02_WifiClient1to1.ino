//https://tom2rd.sakura.ne.jp/wp/2019/09/05/post-9861/

#define cdsPin 33 //INPUTA:33 INPUTB:32
float ain,vo,rf;

/*クライアント側*/
#include<WiFi.h>
const char *ssid="ESP32-WiFi-5"; //サーバーのSSID
const char *pass="esp32wifi"; //サーバーのパスワード
static WiFiClient client; //WiFiClient型でclientと宣言

void setup() {
  Serial.begin(115200);
  pinMode(cdsPin, INPUT);
  WiFi.begin(ssid,pass);  //サーバーに接続
  Serial.printf("\n");
  while(WiFi.status()!=WL_CONNECTED)
  {
    Serial.print(".");
    delay(1000);
  }
  Serial.printf("\n");
  Serial.println("WiFi Connected");
  IPAddress ip(192,168,0,5);  //サーバーのIPアドレス
  client.connect(ip,80);  //IPアドレスとポート番号を指定して接続
}

void loop()
{
  //AD値を取得
  float cds_ad = analogRead(cdsPin);

  //AD値を電圧値に変換
  float cds_v = cds_ad * 3.3 / 4096;

  //電圧値より、Lux計算
  float lux = 10000 * cds_v / ( 3.3 - cds_v ) /1000;

  Serial.print(lux);
  Serial.println(" Lux ");

  if(client.connected()==true)
  {
    if(lux > 25){
      client.write(1);
      delay(100);
    }
    else {
      client.write(2);
      delay(100);
    }
  }
}
