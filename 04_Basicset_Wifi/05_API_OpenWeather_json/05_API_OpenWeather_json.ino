//https://openweathermap.org/current

#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h> //Arduino Json by Benoit Blanchon

const char* ssid = "xxxxx";
const char* password =  "xxxxx";

const String endpoint = "http://api.openweathermap.org/data/2.5/weather?q=kofu,jp&APPID=";
const String key = "xxxxxxxxxxxxxxxxx"; // Your API key

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
    http.begin(endpoint + key); //Specify URL
    int httpCode = http.GET(); //Send a GET request
 
    if (httpCode > 0) { //If there is a reply
      String payload = http.getString();  //Get response (JSON format)
      Serial.println(httpCode);
      Serial.println(payload);

      //Creating a json object
      DynamicJsonDocument forecaseDoc(1024);
      String json = payload;
      deserializeJson(forecaseDoc, json);

      //Extract each data
      String main = forecaseDoc["weather"][0]["main"];

      //Other example
        /*
        int wheatherId = forecaseDoc["weather"][0]["id"];
        String discription = forecaseDoc["weather"][0]["description"];
        float rain = forecaseDoc["rain"]["1h"];
        float snow = forecaseDoc["snow"]["1h"];
        */
        
        Serial.printf("main:%s\n", main);
        
      //Other example 
        /*
        Serial.printf("wheatherId:%d discription:%s rain:%.2f snow:%.2f\n", wheatherId, discription.c_str(), rain, snow);
        */
      }
    
    else {
      Serial.println("Error on HTTP request");
    }

    http.end(); //Free the resources
  }
 
  delay(30000); //Updated every 30 seconds
}
