const int litsnsrPin = 4; //4:ConnectorA only

void setup() {
 Serial.begin(115200);
 pinMode(litsnsrPin, INPUT);
}

void loop() {  
  float litsnsr_ad = analogRead(litsnsrPin); // Read analog data
  float litsnsr_v = litsnsr_ad * 3.3 / 4096; // Calculation of voltage value
  float lux = 10000 * litsnsr_v / (3.3 - litsnsr_v) / 1000; // Calculation of lux value

  //Look at the serial monitor
  Serial.print(lux);
  Serial.print(" Lux : ");
  
  // Change the threshold to suit your environment
  if (lux > 20) { 
    Serial.println("Bright");
    delay(500);
  } else {
    Serial.println("Dark");
    delay(500);
  }
}
