//https://tom2rd.sakura.ne.jp/wp/2019/09/05/post-9861/
//Client side. Connect Light Sensor to "IN" connector.
//Slide switch to 3.3V.

#include<WiFi.h>

#define cdsPin 32
float outVoltage = 3.3; //3.3 or 5.0 Match with slide switch.

const char *ssid="ESP32-WiFi-1";
const char *pass="esp32wifi";
static WiFiClient client;

void setup() {
  Serial.begin(115200);
  pinMode(cdsPin, INPUT);

  WiFi.begin(ssid,pass);

  while(WiFi.status()!=WL_CONNECTED)
  {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("WiFi Connected");
  IPAddress ip(192,168,0,5);  //Server's IP address
  client.connect(ip,80);
}

void loop()
{
  float cds_ad = analogRead(cdsPin); // Read analog data
  float cds_v = cds_ad * outVoltage / 4096; // Calculation of voltage value
  float lux = 10000 * cds_v / (outVoltage - cds_v) / 1000; // Calculation of lux value

  Serial.print(lux);
  Serial.println(" Lux ");

  if(client.connected()==true)
  {
    if(lux > 20){
      client.write(1);
      delay(100);
    }
    else {
      client.write(2);
      delay(100);
    }
  }
}
