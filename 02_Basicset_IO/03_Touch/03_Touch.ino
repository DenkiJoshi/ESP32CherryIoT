const int touchPin = 4;
//4:ConnectorA 9:ConnectorB

void setup() {
  Serial.begin(115200);
  pinMode(touchPin, INPUT);
}

void loop() {
  //Look at the serial monitor
  if (digitalRead(touchPin) == HIGH) {
    Serial.println("Touch!");
  } else {
    Serial.println("...");
  }
  delay(500);
}