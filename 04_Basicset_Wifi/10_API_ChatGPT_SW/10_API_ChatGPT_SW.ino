//https://github.com/fustyles/Arduino/blob/master/ESP32_openAI.ino

#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>

const int swPin = 3; //3:ConnectorA 4:ConnectorB

const char* ssid = "xxxxxxxxxxxx";
const char* password = "xxxxxxxxxx";
String openaiKey = "xxxxxxxxxxxxxxxxxxx"; //Your API Key

//ChatGPT
String role = "You are a helpful assistant.";
String model = "gpt-3.5-turbo";
String system_content = "{\"role\": \"system\", \"content\":\""+ role +"\"}";
String historical_messages = system_content;

void setup() {
  Serial.begin(115200);
  pinMode(swPin, INPUT);
  connectWiFi();
}

void loop() {
  if (digitalRead(swPin) == HIGH) {
    Serial.println(openAI_chat("あなたはギャル風の明るい弾けたキャラクターの女の子です。タメ口で話します。そのキャラクター設定で話してください。こんにちは、今日はいい天気ですね。"));
    delay(1000);
  } else {
    Serial.println(openAI_chat("こんにちは、今日はいい天気ですね。"));
    delay(1000);
  }
  openAI_chat_reset();
}

//WiFiに接続
void connectWiFi(){

  Serial.print("ssid:");
  Serial.print(ssid);
  Serial.println(" に接続します。");

  WiFi.begin(ssid, password);

  Serial.print("WiFiに接続中");
  while(WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }

  Serial.println("接続しました。");

  //IPアドレスの表示
  Serial.print("IPアドレス:");
  Serial.println(WiFi.localIP());

}

String openAI_chat(String message) { 
  WiFiClientSecure client_tcp;
  client_tcp.setInsecure();   //run version 1.0.5 or above
  
  message.replace("\"","'");
  String user_content = "{\"role\": \"user\", \"content\":\""+ message+"\"}";
  historical_messages += ", "+user_content;
  String request = "{\"model\":\""+model+"\",\"messages\":[" + historical_messages + "]}";

  if (client_tcp.connect("api.openai.com", 443)) {
    client_tcp.println("POST /v1/chat/completions HTTP/1.1");
    client_tcp.println("Connection: close"); 
    client_tcp.println("Host: api.openai.com");
    client_tcp.println("Authorization: Bearer " + openaiKey);
    client_tcp.println("Content-Type: application/json; charset=utf-8");
    client_tcp.println("Content-Length: " + String(request.length()));
    client_tcp.println();
    for (int i = 0; i < request.length(); i += 1024) {
      client_tcp.print(request.substring(i, i+1024));
    }
    
    String getResponse="",Feedback="";
    boolean state = false;
    int waitTime = 20000;   // timeout 20 seconds
    long startTime = millis();
    while ((startTime + waitTime) > millis()) {
      Serial.print(".");
      delay(100);      
      while (client_tcp.available()) {
          char c = client_tcp.read();
          //Serial.print(String(c));
          if (state==true) 
            getResponse += String(c);
          if (c == '\n')
            Feedback = "";
          else if (c != '\r')
            Feedback += String(c);
          if (Feedback.indexOf("\",\"content\":\"")!=-1||Feedback.indexOf("\"content\": \"")!=-1)
            state=true;
          if (getResponse.indexOf("\"},")!=-1&&state==true) {
            state=false;
            getResponse = getResponse.substring(0,getResponse.length()-3);
          } else if (getResponse.indexOf("\"")!=-1&&c == '\n'&&state==true) {
            state=false;
            getResponse = getResponse.substring(0,getResponse.length()-2);
          }
          
          startTime = millis();
       }
       if (getResponse.length()>0) {
          client_tcp.stop();
          String assistant_content = "{\"role\": \"assistant\", \"content\":\""+ getResponse+"\"}";
          historical_messages += ", "+assistant_content;
          Serial.println("");
          return getResponse;
       }
    }
    
    client_tcp.stop();
    Serial.println(Feedback);
    return "error";
  }
  else
    return "Connection failed";  
}

void openAI_chat_reset() {
  historical_messages = system_content;
}