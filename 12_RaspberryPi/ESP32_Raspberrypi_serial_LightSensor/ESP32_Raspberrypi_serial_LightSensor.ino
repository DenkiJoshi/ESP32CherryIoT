const int litsnsrPin = 3; //3:ConnectorA 4:ConnectorB

void setup(){
  // Serial Setting
  Serial.begin(115200);

  // Port Setting
  pinMode(litsnsrPin, INPUT);
}

void loop(){
  delay(100);
  
  // Lux計算
  float cds_ad = analogRead(litsnsrPin);
  float cds_v = cds_ad * 3.3 / 4096;
  float lux = 10000 * cds_v / (3.3 - cds_v) / 1000;

  Serial.print(lux);
  Serial.println(" Lux ");
}
