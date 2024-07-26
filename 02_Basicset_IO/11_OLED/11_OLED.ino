#include <SSD1306.h> //ESP8266 and ESP32 OLED driver for SSD1306 displays
#include <Wire.h>

SSD1306 display(0x3c, 1, 3); //(I2C, SDA, SCL) 1,3:ConnectorA 4,5:ConnectorB
 
void setup() {
  display.init(); //Initialization
  display.setFont(ArialMT_Plain_24); //Set Font
  display.drawString(0, 0, "Hello World"); //1st low
  display.drawString(0, 21, "Hello World"); //2nd low
  display.drawString(0, 42, "Hello World"); //3rd low
  display.display(); //Draw
}
 
void loop() {
}
