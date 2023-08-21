//https://magazine.halake.com/entry/esp32_ifttt?utm_source=feed
//温度

#include <WiFi.h>
#include <HTTPClient.h>
#include <OneWire.h> //library manager 
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 33
#define SENSER_BIT    9 

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

const char* ssid = "xxxxx";
const char* password =  "xxxxx";
 
const String endpoint = "https://maker.ifttt.com/trigger/";//定型url
const String eventName = "SchooMyIoT";//IFTTTのEvent name
const String conn = "/with/key/";//定型url
const String key = "xxxxxxxxxxxxx";//IFTTTのYour key
String value ="?value1=";//値 value1=xxxx value2=xxxxx value3=xxxxx

void setup() {
  Serial.begin(115200);
  sensors.setResolution(SENSER_BIT);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
}
 
void loop() {
  sensors.requestTemperatures();              // 温度取得要求
  Serial.println(sensors.getTempCByIndex(0)); //温度の取得&シリアル送信
  
  if ((WiFi.status() == WL_CONNECTED)) {
 
    HTTPClient http; 
    String value ="?value1=" + String(sensors.getTempCByIndex(0));//値 value1=xxxx value2=xxxxx value3=xxxxx
    http.begin(endpoint + eventName + conn + key + value); //URLを指定
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
