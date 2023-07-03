const int SENSOR = 33; //INA33 INB32

void setup() {
  pinMode(SENSOR, INPUT);
  Serial.begin(115200);
}

void loop() {
  if (digitalRead(SENSOR)==HIGH) {
    Serial.println("Touch!");
  } else {
    Serial.println("...");
  }
  delay(500);
}
