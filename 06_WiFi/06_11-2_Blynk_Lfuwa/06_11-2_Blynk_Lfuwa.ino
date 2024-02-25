//https://iotcircuithub.com/blynk-iot-platform-setup-esp8266-esp32/

#define BLYNK_PRINT Serial

/* Fill-in your Template ID (only if using Blynk.Cloud) */
#define BLYNK_TEMPLATE_ID "TMPL6gAgB0BhS"
#define BLYNK_DEVICE_NAME "ESP32Dongle"
#define BLYNK_AUTH_TOKEN "4WyKfEwW4GZxscWdc7p79AXYTw9J3adf"

#define ledPin 25

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h> //Blynk by Volodymyr ver.1.2.0

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "4WyKfEwW4GZxscWdc7p79AXYTw9J3adf";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "AP01-01";
char pass[] = "1qaz2wsx";

void setup()
{
  // Debug console
  Serial.begin(115200);
  ledcSetup(0, 12800, 8);
  ledcAttachPin(ledPin, 0);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
}

BLYNK_WRITE(V0){ //Blynk Virtual Pin
  int ledStatus = param[0].asInt();
  ledcWrite(0, ledStatus);
  Serial.println("---------------");
  Serial.printf("LED Status = %d\r\n", ledStatus);
}
