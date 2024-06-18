const int swPin = 4; //Connect Switch to GPIO4

bool swState = 0;
bool swFlag = 0;

void setup() {
  Serial.begin(115200);
  pinMode(swPin, INPUT);
}

void loop() {

  swState = digitalRead(swPin);
  
  if (swState == LOW) {
    swFlag = !swFlag;
  }

  if(swFlag == 1){
    Serial.println("ON"); //Open the serial monitor and check
    delay(500);
  } else {
    Serial.println("OFF");
    delay(500);
  }
}
