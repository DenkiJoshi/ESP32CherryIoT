//https://github.com/bokunimowakaru/line/blob/master/esp32/ex01_basic/ex01_basic.ino

#include <WiFi.h>
#include <HTTPClient.h>
 
#define line_ch_id "xxxxx"  // Channel ID
#define line_ch_pw "xxxxx"  // Channel secret

#define SSID "xxxxx"
#define PASS "xxxxx"

const char* originalImageUrl = "https://www.pakutaso.com/shared/img/thumb/KAZUHIRO171013120_TP_V.jpg";
const char* previewImageUrl  = "https://www.pakutaso.com/shared/img/thumb/KAZUHIRO171013120_TP_V.jpg";

String get_token(){
    HTTPClient http;  // HTTP request instance
    if(strcmp(line_ch_id,"0000000000") == 0){  // When line_ch_id is not entered
        Serial.println("ERROR: Pls set line_ch_id and pwd");
        return "";
    }
    String url = "https://api.line.me/oauth2/v3/token";
    String body = "grant_type=client_credentials&";
    body += "client_id=" + String(line_ch_id) + "&";
    body += "client_secret=" + String(line_ch_pw);
    http.begin(url);  // Set the HTTP request destination
    http.addHeader("Content-Type","application/x-www-form-urlencoded");
    int httpCode = http.POST(body);  // Send HTTP
    String token="";
    if(httpCode == 200){
        String S = http.getString();  // Store the HTTP response body (text such as JSON)
        int i = S.indexOf("\"access_token\"");
        if((i>0) && (S.substring(i+15, i+16).equals("\""))){  // Find the "access_token" in the JSON string
            token = S.substring(i+16, i+16+174);
            Serial.println(token);
        }
    }else{
        Serial.println("HTTP ERROR: "+String(httpCode));
    }
    http.end();  // End HTTP communication
    return token;
}

int message_to_line(String textMessage){
    String token = get_token();  // Get a token
    if(token.length() != 174){  // Warning when token is too long
        Serial.println("ERROR: Token Length Error; " + String(token.length()));
        return 0;
    }

    HTTPClient http;  // HTTP request instance
    String url = "https://api.line.me/v2/bot/message/broadcast";
    http.begin(url);  // Set the HTTP request destination
    http.addHeader("Content-Type","application/json");
    http.addHeader("Authorization","Bearer " + token);
    
    String json = "{\"messages\":[";
    json += "{\"type\":\"text\",\"text\":\"" + textMessage + "\"}";
    // If you remove the comment, the image will be sent.
    //json += ",{\"type\":\"image\",\"originalContentUrl\":\"" + String(originalImageUrl) + "\",\"previewImageUrl\":\"" + String(previewImageUrl) + "\"}";
    json += "]}";

    Serial.println(json);
    int httpCode = http.POST(json);  // Sending messages over HTTP
    http.end();  // End HTTP communication
    return httpCode;  // HTTP result
}

void setup(){
    Serial.begin(115200);
    Serial.println("LINE Messaging API");

    WiFi.mode(WIFI_STA);  // WiFi to STA mode
    WiFi.begin(SSID,PASS);  // WiFi access point connection
    while(WiFi.status() != WL_CONNECTED){
        Serial.print('.');
        delay(500);
    }
    Serial.println(WiFi.localIP());
}

void loop(){
    message_to_line("[esp32] Test!");  // Free Message:200/Month
    delay(10*60*1000);  // 10 minutes
}
