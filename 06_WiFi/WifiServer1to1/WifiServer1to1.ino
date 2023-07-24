//https://tom2rd.sakura.ne.jp/wp/2019/09/05/post-9861/
/* server側                            */

uint8_t buf[256];

#include<WiFi.h>
const char *ssid="ESP32-WiFi-4"; //SSID
const char *pass="esp32wifi"; //パスワード
const IPAddress ip(192,168,0,9);  //サーバーのIPアドレス
const IPAddress subnet(255,255,255,0);  //サブネットマスク
WiFiServer server(80);

void setup()
{
  Serial.begin(115200);
  pinMode(26, OUTPUT);
  
  WiFi.softAP(ssid,pass);  //SSIDとパスの設定
  delay(100); //接続失敗防止
  WiFi.softAPConfig(ip,ip,subnet);  //IPアドレス、ゲートウェイ、サブネットマスクの設定
  IPAddress myIP = WiFi.softAPIP(); //WiFi.softAPIP()でWiFi起動
  server.begin(); //サーバーを起動(htmlを表示させるため)
  Serial.println();
  /*各種情報を表示*/
  Serial.println("WiFi connected");
  Serial.print("SSID：");
  Serial.println(ssid);
  Serial.print("AP IP address：");
  Serial.println(myIP);
  Serial.println("Server start!");
}

size_t value;

void loop()
{
  //接続したクライアントの情報を得る。
  WiFiClient client = server.available();
  if(client){
    Serial.println("new client");
    while(client.connected()){
      if(client.available()){
        value=client.read();
        Serial.println(value);
        if( value == 1 ) {
          digitalWrite(26, LOW);
          delay(10);
        }
        else {
          digitalWrite(26, HIGH);
          delay(10);
        }
        delay(100);
      }
    }
  }
}
