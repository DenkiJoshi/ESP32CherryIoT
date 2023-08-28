//https://iotcircuithub.com/blynk-iot-platform-setup-esp8266-esp32/

#define BLYNK_PRINT Serial

/* Fill-in your Template ID (only if using Blynk.Cloud) */
#define BLYNK_TEMPLATE_ID "xxxxxxxxxxx"
#define BLYNK_DEVICE_NAME "xxxxxxxxxxxxxxx"
#define BLYNK_AUTH_TOKEN "xxxxxxxxxxxxxxxxxxx"

#define ledPin 33 //OUTPUTA:26 OUTPUT:13

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "xxxxxxxxxxxxxxxxxx";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "xxxxxxxxxxx";
char pass[] = "xxxxxxxxxxxx";

void setup()
{
  // Debug console
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
}

BLYNK_WRITE(V0){ //Blynk Virtual Pin
  int ledStatus = param[0].asInt();
  digitalWrite(ledPin, !ledStatus);
  Serial.println("---------------");
  Serial.printf("LED Status = %d\r\n", ledStatus);
}
