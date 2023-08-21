//https://www.haruirosoleil.com/entry/2020/02/02/101937
//→【arduino_IDE】googlesheetに書き込んでみた

#include <WiFi.h>
#include <WiFiClientSecure.h>

// 接続先のSSIDとパスワード
const char* ssid = "AP01-01"; //無線ルーターのssidを入力
const char* password = "1qaz2wsx"; //無線ルーターのパスワードを入力


void setup() {
  Serial.begin(115200);
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
  String url = "https://script.google.com/macros/s/AKfycbxHtc24-Gw6xo74FObEigp-GW7QhAfn3oweqOzSt9gwEJkpJw7ui7k6ZyHiyCYbBImLRg/exec";  //googlescript web appのurlを入力

  //測定値を準備
  float sensor_data1= 12.34; //仮の測定値
  float sensor_data2= 56.78; //仮の測定値
  float sensor_data3= 91.23; //仮の測定値

  //wifiに接続
  connectWiFi();

  //測定値の表示
  Serial.println(sensor_data1);
  Serial.println(sensor_data2);
  Serial.println(sensor_data3);

  //urlの末尾に測定値を加筆
  url += "?";
  url += "&1_cell=";
  url += sensor_data1;
  url += "&2_cell=";
  url += sensor_data2;
  url += "&3_cell=";
  url += sensor_data3;

  // サーバーにアクセス
  Serial.println("サーバーに接続中...");
  sslclient.setInsecure();//skip verification
  
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
