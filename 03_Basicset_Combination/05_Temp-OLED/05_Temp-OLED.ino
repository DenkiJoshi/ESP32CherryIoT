//C3 only has one I2C channel
#include <Wire.h>
#include <DHT20.h> //DHT20 by RobTillaart
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h> //by Adafruit

DHT20 DHT;

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET     -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

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

  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    for(;;); //Infinite loop when screen initialization fails
  }

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 5);
  display.print(String(Temperature) + "'C"); //1st low
  display.setCursor(0, 25);
  display.print(String(Humidity) + "%"); //2nd low
  display.display(); //Draw
  delay(1000);
  Wire.end();
}
