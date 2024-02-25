//https://www.ekit-tech.com/?p=3434

#include <WiFi.h>
#include <WiFiClientSecure.h>

// WiFi Setting
const char* ssid     = "xxxxx";
const char* password = "xxxxx";

// LINE Notify Setting
const char* host = "notify-api.line.me";
const char* token = "xxxxxxxxxxxxxxxxxxxx"; //Your API key
const char* message = "Hello, I'm ESP32";

int swPin = 32;
bool state = 0;

void setup(){
  Serial.begin(115200);
  pinMode(swPin,INPUT);

  connectWiFi();
}

void loop(){
  state = digitalRead(swPin);

  if (state) {
    send_line();
  }
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

void send_line() {
  //Access to HTTPS (SSL communication)
  WiFiClientSecure client;
  //Required when connecting without verifying the server certificate
  client.setInsecure();

  Serial.println("Try");

  //SSL connection to Line's API server (port 443: https)
  if (!client.connect(host, 443)) {
    Serial.println("Connection failed");
    return;
  }
  Serial.println("Connected");

  // Send request
  String query = String("message=") + String(message);
  String request = String("") +
    "POST /api/notify HTTP/1.1\r\n" +
    "Host: " + host + "\r\n" +
    "Authorization: Bearer " + token + "\r\n" +
    "Content-Length: " + String(query.length()) +  "\r\n" + 
    "Content-Type: application/x-www-form-urlencoded\r\n\r\n" +
    query + "\r\n";
  client.print(request);
 
  // Wait until reception is complete
  while (client.connected()) {
    String line = client.readStringUntil('\n');
    if (line == "\r") {
      break;
    }
  }
  
  String line = client.readStringUntil('\n');
  Serial.println(line);
}