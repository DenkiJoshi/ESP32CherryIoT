//https://tom2rd.sakura.ne.jp/wp/2019/09/05/post-9861/
/* server側                            */

#include "SoftwareSerial.h" //EspSoftwareSerial by Peter Lerup
#include "DFRobotDFPlayerMini.h"

uint8_t buf[256];

SoftwareSerial mySoftwareSerial;
DFRobotDFPlayerMini myDFPlayer;

#include<WiFi.h>
const char *ssid="ESP32-WiFi-4"; //SSID
const char *pass="esp32wifi"; //パスワード
const IPAddress ip(192,168,0,9);  //サーバーのIPアドレス
const IPAddress subnet(255,255,255,0);  //サブネットマスク
WiFiServer server(80);

void setup()
{
  Serial.begin(115200);
  mySoftwareSerial.begin(9600, SWSERIAL_8N1, 22, 21, false, sizeof(buf)); //Speed, ?, RX(26), TX(27), ?, buffer
  myDFPlayer.begin(mySoftwareSerial);
  myDFPlayer.volume(10);  //Set volume value. From 0 to 30
  
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
          myDFPlayer.play(random(1, 5));
          delay(10);
        }
        delay(100);
      }
    }
  }
}
