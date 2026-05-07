//https://www.haruirosoleil.com/entry/2020/02/02/101937

#include <WiFi.h>
#include <WiFiClientSecure.h>

// WiFi Setting
const char* ssid = "xxxxxx"; 
const char* password = "xxxxxx";

const int litsnsrPin = 3; //3:ConnectorA 4:ConnectorB

void setup() {
  Serial.begin(115200);
  pinMode(litsnsrPin, INPUT);
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
  String url = "https://script.google.com/macros/s/xxxxxxxxxxxxxx/exec";  //googlescript web app url

  //Prepare measurements
  float litsnsr_ad = analogRead(litsnsrPin); // Read analog data
  float litsnsr_v = litsnsr_ad * 3.3 / 4096; // Calculation of voltage value
  float lux = 10000 * litsnsr_v / (3.3 - litsnsr_v) / 1000; // Calculation of lux value

  Serial.print(lux);
  Serial.println(" Lux ");
  
  float sensor_data1= lux;

  //Connect WiFi
  connectWiFi();

  //Display of measured values
  Serial.println(sensor_data1);
  
  //Add measurement value to the end of the URL
  url += "?";
  url += "&1_cell=";
  url += sensor_data1;
 
  //Access server
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
  Serial.println("");

  //Disconnect WiFi
  WiFi.mode(WIFI_OFF);
}
