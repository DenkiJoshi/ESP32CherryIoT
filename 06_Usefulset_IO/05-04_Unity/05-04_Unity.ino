#include <WiFi.h>
#include <WiFiUdp.h>

const char* ssid = "Hamako-pixel";
const char* password = "show4900";
const char* client_address = "192.168.235.196";
const int client_port = 22222;
const int server_port = 22224;

WiFiUDP udp;

typedef union {
  short sval[3]; // 3つのショート型データを送信
  uint8_t bval[6]; // 符号なしバイト型
} UDPData;
UDPData s_upd_message_buf;

int x = 4792;
int y = 966;
int z = 7093;

void setup() {
  // 甲府市相生交差点
  //x = 35.658365; //ちょっと移動した先は35.658522。ゴールは35.666241,
  //z = 138.566798; //ちょっと移動した先は138.566830。ゴールは138.568229
  
  Serial.begin(115200);
  delay(500);

  WiFi.disconnect(true, true);
  Serial.println("Connecting to WiFi to : " + String(ssid));
  delay(100);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
  }
  Serial.println("WiFi connected.");
  Serial.print("WiFi connected. ESP32's IP address is : ");
  Serial.println(WiFi.localIP());

  udp.begin(server_port);
  delay(500);
}

void sendUDP() {
  String test = "";

  udp.beginPacket(client_address, client_port);

  udp.write(s_upd_message_buf.bval[0]);
  udp.write(s_upd_message_buf.bval[1]);
  udp.write(s_upd_message_buf.bval[2]);
  udp.write(s_upd_message_buf.bval[3]);
  udp.write(s_upd_message_buf.bval[4]);
  udp.write(s_upd_message_buf.bval[5]);

  test += String(s_upd_message_buf.sval[0]) + ", ";
  test += String(s_upd_message_buf.sval[1]) + ", ";
  test += String(s_upd_message_buf.sval[2]) + ", ";
  
  Serial.println("[SEND] " + test );

  udp.endPacket();
}

void loop() {
  //s_upd_message_buf.sval[0] = (short)(x * 1000); // 0.005 刻みなので 1000 倍して整数に変換
  s_upd_message_buf.sval[0] = x;
  s_upd_message_buf.sval[1] = y;
  s_upd_message_buf.sval[2] = z;

  sendUDP();

  x -= 8;
  y += 1;
  z -= 30;

  delay(500);
}