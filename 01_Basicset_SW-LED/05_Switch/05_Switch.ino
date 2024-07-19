const int swPin = 0;
//0:ConnectorA 4:ConnectorB

bool swState = 0;

void setup() {
  Serial.begin(115200);
  pinMode(swPin, INPUT);
}

void loop() {

  swState = digitalRead(swPin);
  
  if (swState == HIGH) {
    //Look at the serial monitor
    Serial.println("Pushed"); 
    delay(500);
  } else {
    Serial.println("Not Pushed");
    delay(500);
  }
  
}
