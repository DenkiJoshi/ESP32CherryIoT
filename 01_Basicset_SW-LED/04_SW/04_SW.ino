const int swPin = 4; //Connect Switch to GPIO4

bool swState = 0;

void setup() {
  Serial.begin(115200);
  pinMode(swPin, INPUT);
}

void loop() {

  swState = digitalRead(swPin);
  
  if (swState == LOW) {
    Serial.println("Pushed"); //Open the serial monitor and check
    delay(500);
  } else {
    Serial.println("Not Pushed");
    delay(500);
  }
  
}
