//https://www.haruirosoleil.com/entry/2020/02/02/101937

#include <WiFi.h>
#include <WiFiClientSecure.h>

// 接続先のSSIDとパスワード
const char* ssid = "xxxxxx"; //無線ルーターのssidを入力
const char* password = "xxxxxx"; //無線ルーターのパスワードを入力

#define cdsPin 33 //INPUTA:33 INPUTB:32


void setup() {
  Serial.begin(115200);
  pinMode(cdsPin, INPUT);
}


void loop() {
  sendData();
  delay(10000);
}


//WiFiに接続
void connectWiFi(){

  Serial.print("ssid:");
  Serial.print(ssid);
  Serial.println(" に接続します。");

  WiFi.begin(ssid, password);

  Serial.print("WiFiに接続中");
  while(WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("接続しました。");

  //IPアドレスの表示
  Serial.print("IPアドレス:");
  Serial.println(WiFi.localIP());
}

 

//測定データの送信
void sendData(){

  WiFiClientSecure sslclient;

  const char* server = "script.google.com";
  String url = "https://script.google.com/macros/s/xxxxxxxxxxxxxx/exec";  //googlescript web appのurlを入力

  //測定値を準備
  float cds_ad = analogRead(cdsPin);

  float cds_v = cds_ad * 3.3 /4096;

  float lux = 10000 * cds_v / (3.3 - cds_v ) /1000;

  Serial.print(lux);
  Serial.println(" Lux ");
  
  float sensor_data1= lux; //仮の測定値
  

  //wifiに接続
  connectWiFi();

  //測定値の表示
  Serial.println(sensor_data1);
  

  //urlの末尾に測定値を加筆
  url += "?";
  url += "&1_cell=";
  url += sensor_data1;
 

  // サーバーにアクセス
  Serial.println("サーバーに接続中...");

  //データの送信
  if (!sslclient.connect(server, 443)) {
    Serial.println("接続に失敗しました");
    Serial.println("");//改行
    return;
  }

  Serial.println("サーバーに接続しました");

  sslclient.println("GET " + url);
  delay(1000); //私の環境ではここに待ち時間を入れないとデータが送れないことがある
  sslclient.stop();

  Serial.println("データ送信完了");
  Serial.println("");//改行

  //WiFiを切断
  WiFi.mode(WIFI_OFF);
}
