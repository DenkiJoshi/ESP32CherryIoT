#include <DHT20.h> //DHT20 by RobTillaart
#include <Wire.h>

DHT20 DHT;

void setup() {
  Serial.begin(115200);
  Wire.begin(); //Uses I2C, connectorB only
}

void loop() {
  DHT.read();
  float Temperature = DHT.getTemperature();
  float Humidity = DHT.getHumidity();
  //Look at the serial monitor
  Serial.print(String(Temperature) + "℃");
  Serial.print(" / ");
  Serial.println(String(Humidity) + "％");
  delay(500);
}

