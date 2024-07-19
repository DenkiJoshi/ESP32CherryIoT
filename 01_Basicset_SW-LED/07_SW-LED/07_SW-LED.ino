const int swPin = 0; //ConnectorA
const int ledPin = 4; //ConnectorB

bool swState = 0;

void setup() {
  Serial.begin(115200);
  pinMode(swPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {

  swState = digitalRead(swPin);
  
  if (swState == HIGH) {
    digitalWrite(ledPin, HIGH); //ON
    Serial.println("Pushed");
    delay(300);
  } else {
    digitalWrite(ledPin, LOW); //OFF
    Serial.println("Not Pushed");
    delay(300);
  }
}