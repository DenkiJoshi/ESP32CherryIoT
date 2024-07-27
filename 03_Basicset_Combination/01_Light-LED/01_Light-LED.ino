const int litsnsrPin = 3; //3:ConnectorA 4:ConnectorB
const int ledPin = 4; //3:ConnectorA 4:ConnectorB 10:Builtin

void setup() {
  Serial.begin(115200);
  pinMode(litsnsrPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  float litsnsr_ad = analogRead(litsnsrPin); // Read analog data
  float litsnsr_v = litsnsr_ad * 3.3 / 4096; // Calculation of voltage value
  float lux = 10000 * litsnsr_v / (3.3 - litsnsr_v) / 1000; // Calculation of lux value

  //Look at the serial monitor
  Serial.print(lux);
  Serial.print(" Lux : ");
  
  // Change the threshold to suit your environment
  if (lux > 20) { 
    digitalWrite(ledPin, LOW); //OFF
    Serial.println("Bright");
    delay(500);
  } else {
    digitalWrite(ledPin, HIGH); //ON
    Serial.println("Dark");
    delay(500);
  }
}
