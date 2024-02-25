//Connect LightSensor to "IN" connector.
//Slide switch to 3.3V.
//After writing the program, check the serial monitor.

#define cdsPin 32

float outVoltage = 3.3; //3.3 or 5.0 Match with slide switch.

void setup() {
 Serial.begin(115200);
 pinMode(cdsPin, INPUT);
}

void loop() {  
  float cds_ad = analogRead(cdsPin); // Read analog data
  float cds_v = cds_ad * outVoltage / 4096; // Calculation of voltage value
  float lux = 10000 * cds_v / (outVoltage - cds_v) / 1000; // Calculation of lux value

  Serial.print(lux);
  Serial.print(" Lux : ");

  if (lux > 20) { // Change the threshold to suit your environment
    Serial.println("Bright");
    delay(500);
 
  } else {
    Serial.println("Dark");
    delay(500);
  }
}
