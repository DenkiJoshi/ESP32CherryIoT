const int ledPin = 3; //3:ConnectorA 4:ConnectorB
byte val;

void setup(){
  // Serial Setting
  Serial.begin(115200);

  // Port Setting
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

void loop(){
  delay(100);
  if(Serial.available() > 0){
    val = Serial.read();
    if(val == 'A'){
      digitalWrite(ledPin, HIGH);
    } else {
      digitalWrite(ledPin, LOW);
    }
  }
}
