#define hallpin 32 //INA:33 INB:32

void setup() {
  Serial.begin(115200);
  pinMode(hallpin,INPUT);
  
}

void loop() {
  int base = 1650; // ゼロガウス(0G) = 2.5V(2500mV)
   // アナログ入力の値を電圧に変換(mV)
  float voltage =  (analogRead(hallpin) / 4096.0) * 3.3 * 1000;
  float gauss = abs((voltage - base) / 3.3); // 1ガウス(1G) = 5mV
  Serial.print(gauss);
  Serial.println("gauss");
  delay(500);
  //磁石のプラスチック側（N極）をHallセンサーの「Hall」シルク側へ近づけるとgauss値が高くなる。 
}
