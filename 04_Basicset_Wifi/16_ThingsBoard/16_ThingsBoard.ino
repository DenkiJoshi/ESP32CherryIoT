#include <DHT20.h> // DHT20 by RobTillaart
#include <Wire.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <PubSubClient.h>

// ===== WiFi Setting =====
const char* ssid = "xxxxx";
const char* password = "xxxxx";

// ===== ThingsBoard Setting =====
const char* mqtt_server = "thingsboard.cloud";
const int mqtt_port = 8883;
const char* token = "xxxxx";

// ===== Telemetry Key =====
const char* temperature_key = "temperature";
const char* humidity_key = "humidity";

// ===== TempSensor Setting =====
DHT20 DHT;

// ===== MQTT Setting =====
WiFiClientSecure espClient;
PubSubClient client(espClient);

// ===== GPIO =====
const int ledPin = 4; // GPIO4 : LED

// ===== MQTT Callback =====
void callback(char* topic, byte* payload, unsigned int length) {
  String topicStr = String(topic);
  String message;

  for (unsigned int i = 0; i < length; i++) {
    message += (char)payload[i];
  }

  Serial.println("[MQTT] Topic: " + topicStr);
  Serial.println("[MQTT] Payload: " + message);

  if (topicStr.startsWith("v1/devices/me/rpc/request/")) {
    // Extract the request ID
    String requestId = topicStr.substring(strlen("v1/devices/me/rpc/request/"));

    // setState(true/false)
    if (message.indexOf("\"method\":\"setState\"") >= 0) {
      bool ledState = message.indexOf("true") >= 0;
      digitalWrite(ledPin, ledState ? HIGH : LOW);
      Serial.println(ledState ? "LED ON" : "LED OFF");
    }

    // getState : Returns the current LED state
    else if (message.indexOf("\"method\":\"getState\"") >= 0) {
      bool currentState = digitalRead(ledPin) == HIGH;
      String responseTopic = "v1/devices/me/rpc/response/" + requestId;
      String responsePayload = currentState ? "true" : "false";
      client.publish(responseTopic.c_str(), responsePayload.c_str());
      Serial.println("Reported LED state: " + responsePayload);
    }
  }
}


void InitWiFi() {
  Serial.print("Connecting to WiFi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");
}

void reconnect() {
  while (!client.connected()) {
    Serial.println("[TB] Connecting to ThingsBoard...");
    if (client.connect("ESP32C3Client", token, NULL)) {
      Serial.println("[TB] Connected to ThingsBoard!");

      // Subscribe to receive RPC
      client.subscribe("v1/devices/me/rpc/request/+");
    } else {client.setCallback(callback);
      Serial.print("[TB] Failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void setup() {
  delay(1000);
  Serial.begin(115200);
  Wire.begin(1, 3); // SDA = GPIO1, SCL = GPIO3
  pinMode(ledPin, OUTPUT); // GPIO4 Initialization
  digitalWrite(ledPin, LOW);

  espClient.setInsecure();
  InitWiFi();

  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback); // MQTT callback settings
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // Read TempSensor
  DHT.read();
  float humidity = DHT.getHumidity();
  float temperature = DHT.getTemperature();

  if (!isnan(humidity) && !isnan(temperature)) {
    Serial.print("Temperature: ");
    Serial.println(temperature);
    Serial.print("Humidity: ");
    Serial.println(humidity);

    // Send JSON
    String payload = "{";
    payload += "\"" + String(temperature_key) + "\":" + String(temperature, 2) + ",";
    payload += "\"" + String(humidity_key) + "\":" + String(humidity, 2);
    payload += "}";
    client.publish("v1/devices/me/telemetry", payload.c_str());
  }

  delay(10000); // 10sec
}
