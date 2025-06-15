const int swPin = 3; //3:ConnectorA 4:ConnectorB
const int ledPin = 4; //3:ConnectorA 4:ConnectorB 10:Builtin

bool ledState = 0;
 
void setup() {
  pinMode(swPin, INPUT);
  pinMode(ledPin, OUTPUT);
  attachInterrupt(swPin, LED_blink, FALLING);
}

void loop() {
  digitalWrite(ledPin, ledState);
}

void LED_blink(){
  delay(10);
  ledState = !ledState;
}