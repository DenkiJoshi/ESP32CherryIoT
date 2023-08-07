//https://home.openweathermap.org/
//https://openweathermap.org/current

#include <WiFi.h>
#include <HTTPClient.h>
 
const char* ssid = "AP01-01";
const char* password =  "1qaz2wsx";
 
const String endpoint = "http://api.openweathermap.org/data/2.5/weather?q=matsue,jp&APPID=";
const String key = "YOUR API";
 
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
        Serial.println(httpCode);
        Serial.println(payload);
      }
 
    else {
      Serial.println("Error on HTTP request");
    }
 
    http.end(); //Free the resources
  }
 
  delay(30000);   //30秒おきに更新
 
}
