#include <OneWire.h> //library manager 
#include <DallasTemperature.h>
  
#define ONE_WIRE_BUS 33 //INA:33 INB:32
#define SENSER_BIT    9      // 精度の設定bit
  
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
  
void setup(void) {
  Serial.begin(115200); //温度表示確認用
  sensors.setResolution(SENSER_BIT);
}
  
void loop(void) {
  sensors.requestTemperatures();              // 温度取得要求
  Serial.println(sensors.getTempCByIndex(0)); //温度の取得&シリアル送信
}
