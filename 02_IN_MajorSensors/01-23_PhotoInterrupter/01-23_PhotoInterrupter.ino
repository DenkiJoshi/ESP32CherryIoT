#define ruptPin 33 //INA33 INB32

void setup()
{
  pinMode(ruptPin, INPUT);
  Serial.begin(115200);
}

void loop()
{
  Serial.println(digitalRead(ruptPin));
  delay(100);
}
