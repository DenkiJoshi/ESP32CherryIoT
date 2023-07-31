//https://www.mgo-tec.com/blog-entry-esp-wroom-32-esp32-wifi-smartphone-led-switch.html/4

#include <WiFi.h>

const char* ssid = "AP01-01";
const char* password = "1qaz2wsx";
 
WiFiServer server(80);
 
void setup()
{
    delay(1000);
    Serial.begin(115200);
    pinMode(26, OUTPUT);      // set the LED pin mode
 
    delay(10);
 
    Serial.println();
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
 WiFiClient client = server.available();
 
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
          digitalWrite(26, LOW);
        }
        if (currentLine.endsWith("GET /?1=OFF")) {
          digitalWrite(26, HIGH);
        }
      }
    }
     
    client.stop();
    Serial.println("client disonnected");
  }
}
