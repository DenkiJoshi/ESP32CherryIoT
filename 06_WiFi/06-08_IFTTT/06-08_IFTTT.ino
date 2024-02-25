//https://magazine.halake.com/entry/esp32_ifttt?utm_source=feed

#include <WiFi.h>
#include <HTTPClient.h>
 
const char* ssid = "xxxxx";
const char* password =  "xxxxx";
 
const String endpoint = "https://maker.ifttt.com/trigger/";//定型url
const String eventName = "ESP32Dongle";//IFTTTのEvent Name
const String conn = "/with/key/";//定型url
const String Id = "xxxxxxxxxxxxxxx";//自分のIFTTTのYour Key
const String value ="?value1=aaa&value2=bbbb&value3=ccccc";//値 value1=xxxx value2=xxxxx value3=xxxxx

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
 
    http.begin(endpoint + eventName + conn + Id + value); //URLを指定
    int httpCode = http.GET();  //GETリクエストを送信
 
    if (httpCode == 200) { //返答がある場合
      Serial.println("200.OK");
    }else {
      Serial.println("Error on HTTP request");
    }
    http.end(); //Free the resources
  }
  delay(30000);   //30秒おきに更新
}
