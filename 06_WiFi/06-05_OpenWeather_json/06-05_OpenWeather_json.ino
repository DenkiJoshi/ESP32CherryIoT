//https://home.openweathermap.org/
//https://openweathermap.org/current
//https://kohacraft.com/archives/202008170935.html
//https://wak-tech.com/archives/1562
//https://arduinojson.org/v6/doc/upgrade/

#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h> //Arduino Json by Benoit Blanchon
 
const char* ssid = "xxxxx";
const char* password =  "xxxxx";
 
const String endpoint = "http://api.openweathermap.org/data/2.5/weather?q=kofu,jp&APPID=";
const String key = "Your API Key";
 
void setup() {
 
  Serial.begin(115200);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
 
  Serial.println("Connected to the WiFi network");
 
}
 
void loop() {
 
  if ((WiFi.status() == WL_CONNECTED)) {
 
    HTTPClient http;
 
    http.begin(endpoint + key); //URLを指定
    int httpCode = http.GET();  //GETリクエストを送信
 
    if (httpCode > 0) { //返答がある場合
 
        String payload = http.getString();  //返答（JSON形式）を取得
        //Serial.println(httpCode);
        //Serial.println(payload);

        //jsonオブジェクトの作成
        DynamicJsonDocument forecaseDoc(1024);
        String json = payload;
        deserializeJson(forecaseDoc, json);

        //各データを抜き出し
        //int wheatherId = forecaseDoc["weather"][0]["id"];
        //String discription = forecaseDoc["weather"][0]["description"];
        //float rain = forecaseDoc["rain"]["1h"];
        //float snow = forecaseDoc["snow"]["1h"];
        
        String main = forecaseDoc["weather"][0]["main"];
        
        //Serial.printf("wheatherId:%d discription:%s rain:%.2f snow:%.2f\n", wheatherId, discription.c_str(), rain, snow);
        
        Serial.printf("main:%s\n", main);
      }
 
    else {
      Serial.println("Error on HTTP request");
    }
 
    http.end(); //Free the resources
  }
 
  delay(30000);   //30秒おきに更新
 
}
