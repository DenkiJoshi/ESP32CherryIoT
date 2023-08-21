#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid     = "xxxxx";
const char* password = "xxxxx";

const String maker_Event = "SchooMyIoT"; // Maker Webhooks
const String maker_Key   = "xxxxxxxxxxxxxxxx"; // Maker Webhooks
String url = "https://maker.ifttt.com/trigger/" + maker_Event + "/with/key/" + maker_Key;

int i = 0;
bool current_button_state = false;
bool before_button_state = false;
unsigned long counter = 0;
int http_code;


HTTPClient http;
void setup(){
    Serial.begin(115200);
    WiFi.begin(ssid,password);
    Serial.print("connecting to WiFi.");
    while(WiFi.status() != WL_CONNECTED){
        delay(100);
        i++;
        Serial.print(".");
        if(i == 100){
            i = 0;
            return;
        }
    }
    Serial.println("Connected!!");

    http.begin(url);

    pinMode(33,INPUT_PULLUP);
}

void loop(){
    if(digitalRead(33) == LOW){
        if(current_button_state == true) return;
        Serial.println("press!");
        current_button_state = true;
        if(!(millis() - counter >= 10000)) return;
        http_code = http.GET();
        if(!(http_code > 0)){
            Serial.println("request failed!! try again");
            return;
        }
        Serial.println("Send to LINE");
        counter = millis();
    }else{
        current_button_state = false;
    }
}
