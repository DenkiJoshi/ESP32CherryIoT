const int ruptPin = 3; //3:ConnectorA 5:ConnectorB

void setup(){
  pinMode(ruptPin, INPUT);
  Serial.begin(115200);
}

void loop(){
  //Look at the serial monitor
  if (digitalRead(ruptPin)==LOW) {
    Serial.println("Interrupt!");
  } else {
    Serial.println("...");
  }
  delay(500);
}
