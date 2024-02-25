//Connect Temp-Humidity Sensor to "IN" connector.
//Slide switch to 3.3V.
//After writing the program, check the serial monitor.

#include <DHT.h> //DHT sensor library by Adafluit

#define dhtPin 32
#define dhtModel DHT11

DHT dht(dhtPin, dhtModel);

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop(){
  float Temperature = dht.readTemperature();
  float Humidity = dht.readHumidity();

  if (isnan(Humidity) || isnan(Temperature)) {
    Serial.println("ERROR");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(Temperature);
  Serial.print("[℃]");
  Serial.print("  ");
  Serial.print("Humidity: "); 
  Serial.print(Humidity);  
  Serial.println("[%]");

  delay(2000);
}