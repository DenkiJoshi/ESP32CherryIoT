//Connect PushSwitch(Button) to "IN" connector.
//Slide switch to 3.3V.
//After writing the program, check the serial monitor.

#define swPin 32

bool state = 0;
bool flag = 0;

void setup() {
  Serial.begin(115200);
  pinMode(swPin, INPUT);
}

void loop() {
  state = digitalRead(swPin); //Check switch status. If pushed, "LOW"
  if (state == LOW) {
    flag = !flag;
  }

  if(flag == 1){
    Serial.println("ON");
    delay(500);
  } else {
    Serial.println("OFF");
    delay(500);
  }
}
