//Connect PushSwitch(Button) to "IN" connector.
//Slide switch to 3.3V.
//After writing the program, check the serial monitor.

#define swPin 32

bool state = 0;

void setup() {
  Serial.begin(115200);
  pinMode(swPin, INPUT);
}

void loop() {
  state = digitalRead(swPin); //Check switch status. If pushed, "LOW"
  if (state == LOW) {
    Serial.println("Pushed");
    delay(500);
  } else {
    Serial.println("Not Pushed");
    delay(500);
  }
}
