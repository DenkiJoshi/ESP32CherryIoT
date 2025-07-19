#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <PubSubClient.h>
#include <DHT20.h> // by Rob Tillaart
#include <Wire.h>

// ======= WiFi Setting =======
const char* ssid = "xxxxx";
const char* password = "xxxxx";

// ======= AWS IoT Core Setting =======
const char* awsEndpoint = "xxxxxxxxx-ats.iot.ap-northeast-1.amazonaws.com";
const int awsPort = 8883;
const char* thingName = "ESP32CherryIoT_Device001";
const char* topic = "esp32cherryiot/temperature/ESP32CherryIoT_Device001";

// ======= Certificate of Authenticity =======
const char* certificate_pem_crt = R"EOF(
-----BEGIN CERTIFICATE-----
xxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxx
-----END CERTIFICATE-----
)EOF";

const char* private_pem_key = R"EOF(
-----BEGIN RSA PRIVATE KEY-----
xxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxx
-----END RSA PRIVATE KEY-----
)EOF";

const char* amazon_ca = R"EOF(
-----BEGIN CERTIFICATE-----
xxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxx
-----END CERTIFICATE-----
)EOF";

// ======= DHT20 Initialization =======
DHT20 DHT;

// ======= MQTT =======
WiFiClientSecure net;
PubSubClient client(net);

// ======= AWS connection =======
void connectAWS() {
  Serial.println("[INFO] Start WiFi connection");
  WiFi.begin(ssid, password);
  int wifi_retry = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    wifi_retry++;
    if (wifi_retry > 40) {
      Serial.println("\n[ERROR] WiFi connection failed. Reset.");
      ESP.restart();
    }
  }
  Serial.println("\n[INFO] WiFi connection successful");

  Serial.println("[INFO] Setting up certificate...");
  net.setCACert(amazon_ca);
  net.setCertificate(certificate_pem_crt);
  net.setPrivateKey(private_pem_key);

  client.setServer(awsEndpoint, awsPort);

  Serial.println("[INFO] Start connecting to AWS IoT Core");
  int mqtt_retry = 0;
  while (!client.connected()) {
    if (client.connect(thingName)) {
      Serial.println("[INFO] MQTT connection successful");
    } else {
      Serial.print(".");
      delay(1000);
      mqtt_retry++;
      if (mqtt_retry > 20) {
        Serial.println("\n[ERROR] MQTT connection failed. Restarting.");
        ESP.restart();
      }
    }
  }
}

// ======= Setup =======
void setup() {
  Serial.begin(115200);
  delay(2000); // For stabilizing serial connection
  Serial.println("\n====== ESP32 startup ======");
  Wire.begin(1, 3); // SDA=GPIO1, SCL=GPIO3
  Serial.println("[INFO] I2C initialization complete");

  DHT.begin();
  Serial.println("[INFO] DHT20 initialization complete");

  connectAWS();
}

void loop() {
  if (!client.connected()) {
    Serial.println("[WARN] Reconnecting MQTT...");
    connectAWS();
  }

  Serial.println("[INFO] Start reading DHT20 sensor");
  DHT.read();
  float temperature = DHT.getTemperature();
  Serial.print("[INFO] Temperature acquisition completed: ");
  Serial.print(temperature);
  Serial.println(" ℃");

  // Send in JSON format
  String payload = "{";
  payload += "\"deviceId\":\"ESP32CherryIoT_Device001\",";
  payload += "\"temperature\":" + String(temperature, 2);
  payload += "}";

  Serial.print("[INFO] MQTT Send: ");
  Serial.println(payload);
  client.publish(topic, payload.c_str());

  delay(10000); // 10sec
}
