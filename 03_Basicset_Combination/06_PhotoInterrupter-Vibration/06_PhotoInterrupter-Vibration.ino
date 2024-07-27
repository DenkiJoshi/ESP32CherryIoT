const int ruptPin = 3; //3:ConnectorA 4:ConnectorB
const int vibPin = 4; //3:ConnectorA 4:ConnectorB

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
    delay(300);
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

