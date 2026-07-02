const int pressPin = 3; //3:ConnectorA 4:ConnectorB

float ain,vo,rf;

void setup() {
  Serial.begin(115200);
  pinMode(pressPin, INPUT);
}

void loop() {
  ain = analogRead(pressPin);
  vo = ain * 3.3 / 4096;
  rf = 10000 * vo / (3.3 - vo);
  Serial.print( rf );
  Serial.println( "g" );
  delay( 1000 );
}
