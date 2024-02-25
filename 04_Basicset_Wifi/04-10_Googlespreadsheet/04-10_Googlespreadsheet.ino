//https://www.haruirosoleil.com/entry/2020/02/02/101937

#include <WiFi.h>
#include <WiFiClientSecure.h>

// WiFi Setting
const char* ssid = "xxxxx";
const char* password = "xxxxx";

void setup() {
  Serial.begin(115200);
}

void loop() {
  sendData();
  delay(10000);
}

void connectWiFi(){
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  //Start WiFi connection
  WiFi.begin(ssid, password);

  //Check WiFi connection status
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void sendData(){

  WiFiClientSecure sslclient;

  const char* server = "script.google.com";
  String url = "https://script.google.com/macros/s/AKfycbwatdrSt50TSvsoO5S1-7qFu4zQAKA1sp6lAMMN4QQiJ4WWjKFUgz1TY-5Fmi3BNBpd/exec";  //googlescript web appのurlを入力

  //Prepare measurements
  float sensor_data1= 11.11; //dammy data
  float sensor_data2= 22.22; //dammy data
  float sensor_data3= 33.33; //dammy data

  //Connect WiFi
  connectWiFi();

  //Display of measured values
  Serial.println(sensor_data1);
  Serial.println(sensor_data2);
  Serial.println(sensor_data3);

  //Add measurement value to the end of the URL
  url += "?";
  url += "&1_cell=";
  url += sensor_data1;
  url += "&2_cell=";
  url += sensor_data2;
  url += "&3_cell=";
  url += sensor_data3;

  // Access server
  Serial.println("Access server...");
  sslclient.setInsecure(); //skip verification
  
  //Send data
  if (!sslclient.connect(server, 443)) {
    Serial.println("Connection failed!");
    Serial.println("");
    return;
  }

  Serial.println("Connected to server");

  sslclient.println("GET " + url);
  delay(1000); //Waiting for stabilization
  sslclient.stop();

  Serial.println("Data transmission completed");
  Serial.println("");//改行

  //Disconnect WiFi
  WiFi.mode(WIFI_OFF);
}
