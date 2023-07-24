//Connect LightSensor to IN connector

#define cdsPin 32

void setup() {
 Serial.begin(115200);
 pinMode(cdsPin, INPUT);
}

void loop() {  
  float cds_ad = analogRead(cdsPin); // Read analog data
  float cds_v = cds_ad * 3.3 / 4096; // Calculation of voltage value
  float lux = 10000 * cds_v / (3.3 - cds_v) / 1000; // Calculation of lux value

  Serial.print(lux);
  Serial.print(" Lux : ");

  if (lux > 20) {
    Serial.println("High");
    delay(500);
 
  } else {
    Serial.println("Low");
    delay(500);
  }
}
