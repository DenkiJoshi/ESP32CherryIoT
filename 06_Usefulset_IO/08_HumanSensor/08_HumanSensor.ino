const int sensorPin = 3; //3:ConnectorA 4:ConnectorB

void setup()
{
  Serial.begin(115200);
  pinMode(sensorPin, INPUT);
}

void loop()
{
  Serial.println(digitalRead(sensorPin));
  delay(500);
}
