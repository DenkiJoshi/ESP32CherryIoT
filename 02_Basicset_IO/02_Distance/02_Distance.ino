const int trigPin = 4; //4:ConnectorA 9:ConnectorB
const int echoPin = 5; //5:ConnectorA 8:ConnectorB

float measureDist(){
  float Duration = 0; //Received Interval
  float Calc_Dist = 0; //Calculation results from Duration

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); //Ultrasonic output
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  Duration = pulseIn(echoPin, HIGH); //Input from sensor
  Duration = Duration/2; //Half the round trip time
  Calc_Dist = Duration*340*100/1000000; //Set sonic speed to 340 m/s
  return Calc_Dist;
}

void setup() {
  Serial.begin(115200);
  pinMode(echoPin,INPUT);
  pinMode(trigPin,OUTPUT);
}

void loop() {
  //Look at the serial monitor
  Serial.print("Distance:");
  Serial.print(measureDist());
  Serial.println("cm");
  delay(500);
}
