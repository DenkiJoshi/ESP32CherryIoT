const int swPin = 4; //Connect Switch to GPIO4
const int ledPin = 0; //Connect LED to GPIO0

bool swState = 0;

void setup() {
  Serial.begin(115200);
  pinMode(swPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {

  swState = digitalRead(swPin);
  
  if (swState == LOW) {
    digitalWrite(ledPin, HIGH); //ON
    Serial.println("Pushed");
    delay(200);
  } else {
    digitalWrite(ledPin, LOW); //OFF
    Serial.println("Not Pushed");
    delay(200);
  }
}