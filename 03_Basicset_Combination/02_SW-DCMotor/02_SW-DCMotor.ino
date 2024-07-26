const int swPin = 3; //3:ConnectorA 5:ConnectorB
const int motorPin = 5; //3:ConnectorA 5:ConnectorB

bool swState;

void setup() {
  Serial.begin(115200);
  pinMode(swPin, INPUT);
  pinMode(motorPin, OUTPUT);
}

void loop() {

  if (digitalRead(swPin) == HIGH) {
    swState = !swState;
  }

  if (swState == 1) { 
    digitalWrite(motorPin, HIGH); //ON
    Serial.println("ON");
    delay(300);
  } else {
    digitalWrite(motorPin, LOW); //OFF
    Serial.println("OFF");
    delay(300);
  }
  
}
