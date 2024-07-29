//https://openweathermap.org/current

#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "xxxxx";
const char* password =  "xxxxx";

const String endpoint = "http://api.openweathermap.org/data/2.5/weather?q=matsue,jp&APPID=";
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
    }

    else {
      Serial.println("Error on HTTP request");
    }

    http.end(); //Free the resources
  }

  delay(30000); //Updated every 30 seconds
}
