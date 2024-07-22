const int ruptPin = 9;
//4:ConnectorA 9:ConnectorB

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
