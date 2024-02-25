//Connect OLED to "OUT" connector.
//Slide switch to 3.3V.

#include <Wire.h>
#include <SSD1306.h> //ESP8266 and ESP32 OLED driver for SSD1306 displays

SSD1306  display(0x3c, 26, 25); //(I2C, SCL, SDA)
 
void setup() {
  display.init();    //Initialize display
  display.setFont(ArialMT_Plain_24);    //Set Font
  display.drawString(0, 0, "Hello World");    //Display Hello World at position (0,0)
  display.drawString(0, 21, "Hello World");    //Display Hello World at position (0,21)
  display.drawString(0, 42, "Hello World");    //Display Hello World at position (0,42)
  display.display();   //Draws specified information
}
 
void loop() {
}
