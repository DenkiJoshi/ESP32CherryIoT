const int swPin = 3; //3:ConnectorA 5:ConnectorB

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
