const int swPin = 4;
//4:ConnectorA 9:ConnectorB

void setup() {
  Serial.begin(115200);
  pinMode(swPin, INPUT);
}

void loop() {
  if (digitalRead(swPin) == HIGH) {
    //Look at the serial monitor
    Serial.println("Pushed"); 
    delay(500);
  } else {
    Serial.println("Not Pushed");
    delay(500);
  }
}
