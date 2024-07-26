#include <DHT20.h> //DHT20 by RobTillaart
#include <SSD1306.h> //ESP8266 and ESP32 OLED driver for SSD1306 displays
#include <Wire.h>

DHT20 DHT;
SSD1306 display(0x3c, 1, 3); //OLED(I2C, SDA, SCL) 1,3:ConnectorA 4,5:ConnectorB

void setup() {
  Serial.begin(115200);
  Wire.begin(1, 3); //Temp(SDA, SCL)1,3:ConnectorA 4,5:ConnectorB
  display.setFont(ArialMT_Plain_24); //Set Font
}

void loop() {
  DHT.read();
  float Temperature = DHT.getTemperature();
  float Humidity = DHT.getHumidity();
  Serial.print(String(Temperature) + "℃");
  Serial.print(" / ");
  Serial.println(String(Humidity) + "％");
  
  display.init(); //Initialization
  display.drawString(0, 0, String(Temperature) + "℃"); //1st low
  display.drawString(0, 21, String(Humidity) + "%"); //2nd low
  display.display(); //Draw
  
  delay(500);
}
