//C3 only has one I2C channel
#include <DHT20.h> //DHT20 by RobTillaart
#include <SSD1306.h> //ESP8266 and ESP32 OLED driver for SSD1306 displays
#include <Wire.h>

DHT20 DHT;
SSD1306 display(0x3c, 5, 4); //OLED(I2C, SDA, SCL) 1,3:ConnectorA 5,4:ConnectorB

void setup() {
  Serial.begin(115200);
}

void loop() {
  
  //Start Temp-Humidity Sensor
  Wire.begin(1, 3); //Temp(SDA, SCL)1,3:ConnectorA 5,4:ConnectorB 
  DHT.read();
  float Temperature = DHT.getTemperature();
  float Humidity = DHT.getHumidity();
  Serial.print(String(Temperature) + "℃");
  Serial.print(" / ");
  Serial.println(String(Humidity) + "％");
  delay(200);
  Wire.end();
  
  //Start OLED
  Wire.begin(5, 4); //OLED(SDA, SCL)1,3:ConnectorA 5,4:ConnectorB 
  display.init(); //Initialization
  display.setFont(ArialMT_Plain_24); //Set Font
  display.drawString(0, 0, String(Temperature) + "°C"); //1st low
  display.drawString(0, 21, String(Humidity) + "%"); //2nd low
  display.display(); //Draw
  delay(1000);
  Wire.end();
}
