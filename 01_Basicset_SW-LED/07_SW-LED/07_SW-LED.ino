const int swPin = 3; //3:ConnectorA 5:ConnectorB
const int ledPin = 5; //3:ConnectorA 5:ConnectorB 10:Builtin

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