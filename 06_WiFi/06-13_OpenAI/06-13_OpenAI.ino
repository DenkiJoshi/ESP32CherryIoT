//https://github.com/fustyles/Arduino/blob/master/ESP32_openAI.ino

#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>

const char* ssid = "aterm-02f2a5-g";
const char* password = "068602ce2f2bd";
String openaiKey = "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";

//ChatGPT
String role = "You are a helpful assistant.";
String model = "gpt-3.5-turbo";
String system_content = "{\"role\": \"system\", \"content\":\""+ role +"\"}";
String historical_messages = system_content;

//Image generator
String imageSize = "256x256"; // 256x256, 512x512 , 1024x1024

void setup() {
  Serial.begin(115200);
  connectWiFi();
  Serial.println(openAI_chat("私は山梨県に住んでいます。"));
  Serial.println(openAI_chat("私の地域で有名なものを教えてください。"));
  Serial.println(openAI_image("私の地域のイメージ画像を生成してください。"));  
}

void loop() {
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

String openAI_image(String message) { 
  WiFiClientSecure client_tcp;
  client_tcp.setInsecure();   //run version 1.0.5 or above

  String request = "{\"prompt\":\""+ message+"\", \"size\":\""+imageSize+"\", \"n\":1}";
  if (client_tcp.connect("api.openai.com", 443)) {
    client_tcp.println("POST /v1/images/generations HTTP/1.1");
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
          if (String(c)=="\""&&state==true)
            break;           
          if (state==true)
            getResponse += String(c);
          if (c == '\n')
            Feedback = "";
          else if (c != '\r')
            Feedback += String(c);
          if (Feedback.indexOf("\"url\": \"")!=-1)
            state=true;             
          startTime = millis();
       }
       if (getResponse.length()>0) {
          client_tcp.stop();
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