#include<WiFi.h>

const int litsnsrPin = 3; //3:ConnectorA 4:ConnectorB

const char *ssid="ESP32-WiFi-1";
const char *pass="esp32wifi";
static WiFiClient client;

void setup() {
  Serial.begin(115200);
  pinMode(litsnsrPin, INPUT);

  WiFi.begin(ssid,pass);

  while(WiFi.status()!=WL_CONNECTED)
  {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("WiFi Connected");
  IPAddress ip(192,168,0,1);  //Server's IP address
  client.connect(ip,80);
}

void loop()
{
  float litsnsr_ad = analogRead(litsnsrPin); // Read analog data
  float litsnsr_v = litsnsr_ad * 3.3 / 4096; // Calculation of voltage value
  float lux = 10000 * litsnsr_v / (3.3 - litsnsr_v) / 1000; // Calculation of lux value

  Serial.print(lux);
  Serial.println(" Lux ");

  if(client.connected()==true)
  {
    if(lux > 20){
      client.write(1);
      delay(10);
    }
    else {
      client.write(2);
      delay(10);
    }
  }
  delay(500);
}
