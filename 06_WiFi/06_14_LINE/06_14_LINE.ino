//https://www.ekit-tech.com/?p=3434

#include <WiFi.h>
#include <WiFiClientSecure.h>

// WiFi設定
const char* ssid     = "aterm-02f2a5-g";
const char* password = "068602ce2f2bd";

// LINE Notify設定
const char* host = "notify-api.line.me";
const char* token = "CNFTN4p61bZ1wsyRyfzZsFa1n2rTEDoTebFC0dXTLIL";
const char* message = "ピンポーン";

// スイッチに使用するPinの設定
int sw_pin = 32;

void setup()
{
    // スイッチPinを入力に設定
    pinMode(sw_pin,INPUT);

    // シリアルモニタの通信速度
    Serial.begin(115200);

    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    // WiFi接続
    WiFi.begin(ssid, password);

    // WiFiの接続状態を確認
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}

// line通知
void send_line() {

  // HTTPSへアクセス（SSL通信）するためのライブラリ
  WiFiClientSecure client;

  // サーバー証明書の検証を行わずに接続する場合に必要
  client.setInsecure();
  
  Serial.println("Try");
  
  //LineのAPIサーバにSSL接続（ポート443:https）
  if (!client.connect(host, 443)) {
    Serial.println("Connection failed");
    return;
  }
  Serial.println("Connected");

  // リクエスト送信
  String query = String("message=") + String(message);
  String request = String("") +
               "POST /api/notify HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Authorization: Bearer " + token + "\r\n" +
               "Content-Length: " + String(query.length()) +  "\r\n" + 
               "Content-Type: application/x-www-form-urlencoded\r\n\r\n" +
                query + "\r\n";
  client.print(request);
 
  // 受信完了まで待機 
  while (client.connected()) {
    String line = client.readStringUntil('\n');
    if (line == "\r") {
      break;
    }
  }
  
  String line = client.readStringUntil('\n');
  Serial.println(line);
}

// スイッチの変数宣言
int sw_val = 0;

void loop(){

  // スイッチの状態を読み取る
  sw_val = digitalRead(sw_pin);

  // スイッチがONのとき
  if (sw_val) {

    // Lineにリクエストを送信する
    send_line();
  }
  
}