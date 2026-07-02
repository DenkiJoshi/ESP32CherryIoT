const int hallPin = 3; //3:ConnectorA 4:ConnectorB

void setup() {
  Serial.begin(115200);
  pinMode(hallPin, INPUT);
}

void loop() {
  int base = 3300; // Zero Gauss(0G) = 3.3V(3300mV)
   // Convert the analog input value to voltage.(mV)
  float voltage =  (analogRead(hallPin) / 4096.0) * 3.3 * 1000;
  float gauss = abs((voltage - base) / 3.3); // 1Gauss(1G) = 3.3mV
  Serial.print(gauss);
  Serial.println("gauss");
  delay(500); 
}
