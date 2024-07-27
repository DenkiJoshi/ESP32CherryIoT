const int trigPin = 3; //3:ConnectorA 4:ConnectorB
const int echoPin = 1; //1:ConnectorA 5:ConnectorB

float Duration = 0; //Received Interval Time
float Distance = 0; //Calculation results from Duration
  
void setup() {
  Serial.begin(115200);
  pinMode(echoPin,INPUT);
  pinMode(trigPin,OUTPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); //Ultrasonic output
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  Duration = pulseIn(echoPin, HIGH); //Input from sensor
  Duration = Duration/2; //Half the round trip time
  Distance = Duration*340*100/1000000; //Set sonic speed to 340 m/s

  //Look at the serial monitor
  Serial.print("Distance:");
  Serial.print(Distance);
  Serial.println("cm");
  delay(500);
}
