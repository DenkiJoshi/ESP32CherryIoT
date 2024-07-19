const int swPin = 0;
//0:ConnectorA 4:ConnectorB

bool swState = 0;
bool swFlag = 0;

void setup() {
  Serial.begin(115200);
  pinMode(swPin, INPUT);
}

void loop() {

  swState = digitalRead(swPin);
  
  if (swState == HIGH) {
    swFlag = !swFlag;
  }

  if(swFlag == 1){
    //Look at the serial monitor
    Serial.println("ON");
    delay(300);
  } else {
    Serial.println("OFF");
    delay(300);
  }
}
