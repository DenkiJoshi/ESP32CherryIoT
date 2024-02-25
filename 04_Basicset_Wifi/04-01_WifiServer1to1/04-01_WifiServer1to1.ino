//https://tom2rd.sakura.ne.jp/wp/2019/09/05/post-9861/
//Server side. Connect LED to "OUT" connector.
//Slide switch to 3.3V.

#include<WiFi.h>
#define ledPin 25

const char *ssid="ESP32-WiFi-1";
const char *pass="esp32wifi";

const IPAddress ip(192,168,0,5);
const IPAddress subnet(255,255,255,0);
WiFiServer server(80);

void setup(){
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  
  WiFi.softAP(ssid,pass);
  delay(100);
  WiFi.softAPConfig(ip,ip,subnet);
  IPAddress myIP = WiFi.softAPIP(); //WiFi start by WiFi.softAPIP()
  server.begin(); //Server start

  Serial.println("WiFi connected");
  Serial.print("SSID ");
  Serial.println(ssid);
  Serial.print("AP IP address ");
  Serial.println(myIP);
  Serial.println("Server start!");
}

size_t value;

void loop()
{
  WiFiClient client = server.available(); //Get information about connected clients.

  if(client){
    Serial.println("new client");
    while(client.connected()){
      if(client.available()){
        value=client.read();
        Serial.println(value);
        
        if( value == 1 ) {
          digitalWrite(ledPin, LOW);
          delay(10);
        }
        else {
          digitalWrite(ledPin, HIGH);
          delay(10);
        }

        delay(100);
      }
    }
  }
}
