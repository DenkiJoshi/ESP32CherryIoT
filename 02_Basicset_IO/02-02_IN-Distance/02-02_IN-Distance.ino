//Connect Distance sensor to "IN" connector.
//Slide switch to 3.3V.

#define echoPin 33
#define trigPin 32

float Distance(){
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
  Serial.print("Distance:");
  Serial.print(Distance());
  Serial.println("cm");
  delay(500);
}
