#include <WiFi.h>
#include <WiFiClientSecure.h>

// WiFi Setting
const char* ssid     = "xxxxxxx";
const char* password = "xxxxxxx";

const char *ntpServer1 = "pool.ntp.org";
const char *ntpServer2 = "time.nist.gov";
const long gmtOffset_sec = 9 * 3600;
const int daylightOffset_sec = 0;

void setup(){
  Serial.begin(115200);
  connectWiFi();
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer1, ntpServer2);
}

void loop(){
  printLocalTime();
  delay(3000);
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

void printLocalTime() {
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    Serial.println("No time available (yet)");
    return;
  }
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
}