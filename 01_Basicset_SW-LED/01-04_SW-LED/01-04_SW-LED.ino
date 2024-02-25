//Connect PushSwitch(Button) to "IN" connector.
//Connect LED to "OUT" connector
//Slide switch to 3.3V.

#define swPin 32
#define ledPin 25

bool state = 0;

void setup() {
  Serial.begin(115200);
  pinMode(swPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  state = digitalRead(swPin); //Check switch status. If pushed, "LOW" 
  if (state == LOW) {
    digitalWrite(ledPin, HIGH); //LED on
    Serial.println("Pushed");
    delay(200);
  } else {
    digitalWrite(ledPin, LOW); //LED off
    Serial.println("Not Pushed");
    delay(200);
  }
}