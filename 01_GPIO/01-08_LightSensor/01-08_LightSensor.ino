#define sensorPin 33 //INPUTA:33 INPUTB:32

void setup() {
 Serial.begin(115200);
 pinMode(sensorPin, INPUT);
}

void loop() {  
  // R1のAD値を取得
  float cds_ad = analogRead(sensorPin);

  // AD値を電圧値に変換
  float cds_v = cds_ad * 3.3 / 4096;

  // 電圧値より、Lux計算
  float lux = 10000 * cds_v / (3.3 - cds_v) / 1000;

  Serial.print(lux);
  Serial.println(" Lux ");

  if (lux > 20) {
    Serial.println("High lux");
    delay(1000);
 
  } else {
    Serial.println("Low lux");
    delay(1000);
  }
}
