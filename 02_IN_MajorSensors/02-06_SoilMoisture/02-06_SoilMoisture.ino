#define sensorPin 33 //INA:33 INB:32
float moisture = 0;
float sensorValue = 0; 
 
void setup() {
    Serial.begin(115200); 
    pinMode(sensorPin, INPUT);
}
 
void loop() {
    sensorValue = analogRead(sensorPin);
    moisture = sensorValue / 2224 * 100; //初期値2224。水につけてanalogReadした値。
    Serial.print(moisture);
    Serial.println("%");
    delay(1000);
}
