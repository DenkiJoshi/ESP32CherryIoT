const int ruptPin = 3; //3:ConnectorA 5:ConnectorB
const int vibPin = 5; //3:ConnectorA 5:ConnectorB

int interruptCount = 0;

void setup() {
  pinMode(ruptPin, INPUT);
  pinMode(vibPin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  if (digitalRead(ruptPin) == LOW) {
    interruptCount++;
    Serial.println("Interrupt!");
    delay(100);
  }

  if (interruptCount >= 5) {
    digitalWrite(vibPin, HIGH);
    delay(1000);
    digitalWrite(vibPin, LOW);
    interruptCount = 0;
    Serial.println("5 items comming!");
  }
  
  delay(100);
}

