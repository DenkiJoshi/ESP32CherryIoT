#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h> //by Adafruit

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET     -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup()
{
  Wire.begin(1, 3); //(SDA, SCL) 1,3:ConnectorA 5,4:ConnectorB

  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    for(;;); //Infinite loop when screen initialization fails
  }

  display.setTextWrap(false);  // Disable wrapping

}

void loop()
{
  for(int i=0; i<128; i++){
    display.clearDisplay();

    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(i, 25);
    display.print(F("CherryIoT"));

    display.display();
    delay(20);
  }
}