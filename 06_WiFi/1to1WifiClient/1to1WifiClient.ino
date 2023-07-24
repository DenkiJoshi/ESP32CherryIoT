//https://tom2rd.sakura.ne.jp/wp/2019/09/05/post-9861/

#define press_pin 32
float ain,vo,rf;

/*クライアント側*/
#include<WiFi.h>
const char *ssid="ESP32-WiFi-4"; //サーバーのSSID
const char *pass="esp32wifi"; //サーバーのパスワード
static WiFiClient client; //WiFiClient型でclientと宣言

void setup() {
  Serial.begin(115200);
  pinMode(press_pin, INPUT);
  WiFi.begin(ssid,pass);  //サーバーに接続
  Serial.printf("\n");
  while(WiFi.status()!=WL_CONNECTED)
  {
    Serial.print(".");
    delay(1000);
  }
  Serial.printf("\n");
  Serial.println("WiFi Connected");
  IPAddress ip(192,168,0,9);  //サーバーのIPアドレス
  client.connect(ip,80);  //IPアドレスとポート番号を指定して接続
}

void loop()
{
  ain = analogRead(press_pin);
  vo = ain * 3.3 / 4096;
  rf = 10000 * vo / (3.3 - vo);
  Serial.print( rf );
  Serial.println( "g" );
  delay(200);

  if(client.connected()==true)
  {
    if(rf > 5000){
      client.write(1);
      delay(100);
    }
    else {
      client.write(2);
      delay(100);
    }
  }
}
