const int swPin = 3; //3:ConnectorA 4:ConnectorB

bool swState = 0;

void setup() {
  Serial.begin(115200);
  pinMode(swPin, INPUT);
}

void loop() {
  
  if (digitalRead(swPin) == HIGH) {
    swState = !swState;
  }

  if(swState == 1){
    //Look at the serial monitor
    Serial.println("ON");
    delay(300);
  } else {
    Serial.println("OFF");
    delay(300);
  }

}
