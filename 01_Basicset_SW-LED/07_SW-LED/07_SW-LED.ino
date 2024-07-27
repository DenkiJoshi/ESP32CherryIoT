const int swPin = 3; //3:ConnectorA 4:ConnectorB
const int ledPin = 4; //3:ConnectorA 4:ConnectorB 10:Builtin

void setup() {
  Serial.begin(115200);
  pinMode(swPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() { 
  if (digitalRead(swPin) == HIGH) {
    digitalWrite(ledPin, HIGH); //ON
    Serial.println("Pushed");
    delay(300);
  } else {
    digitalWrite(ledPin, LOW); //OFF
    Serial.println("Not Pushed");
    delay(300);
  }
}