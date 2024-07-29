//https://www.mgo-tec.com/blog-entry-esp-wroom-32-esp32-wifi-smartphone-led-switch.html/4
#include <WiFi.h>
const int ledPin = 3; //3:ConnectorA 4:ConnectorB

const char* ssid = "xxxxx";
const char* password = "xxxxx";
 
WiFiServer server(80);
 
void setup()
{
    delay(1000);
    Serial.begin(115200);
    pinMode(ledPin, OUTPUT);
 
    delay(10);
 
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);
 
    WiFi.begin(ssid, password);
 
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
 
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
     
    server.begin();
 
}
 
void loop(){
 WiFiClient client = server.available(); //Get information about connected clients.
 
  if (client) {
    Serial.println("new client");
    String currentLine = "";
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        if (c == '\n') {
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();
 
            client.println("<!DOCTYPE html>");
            client.println("<html>");
            client.println("<head>");
            client.println("<meta name='viewport' content='initial-scale=1.5'>");
            client.println("</head>");
            client.println("<body>");
            client.println("<form method='get'>");
            client.println("<font size='4'>ESP-WROOM-32<br>");
            client.println("Wi-Fi  LED  Switch</font><br>");
            client.println("<br>");
            client.println("<input type='submit' name=0 value='ON' style='background-color:#FF00FF; color:pink;'>");
            client.println("<input type='submit' name=1 value='OFF' style='background-color:#66FFCC; color:skyblue;'>");
            client.println("</form>");
            client.println("</body>");
            client.println("</html>");
 
            client.println();
            break;
          } else {
            currentLine = "";
          }
        } else if (c != '\r') {
          currentLine += c;
        }
 
        if (currentLine.endsWith("GET /?0=ON")) {
          digitalWrite(ledPin, HIGH);
        }
        if (currentLine.endsWith("GET /?1=OFF")) {
          digitalWrite(ledPin, LOW);
        }
      }
    }
     
    client.stop();
    Serial.println("client disconnected");
  }
}
