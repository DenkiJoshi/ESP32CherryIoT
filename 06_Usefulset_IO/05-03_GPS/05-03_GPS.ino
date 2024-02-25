//https://qiita.com/taiyyytai/items/a874497e72fc5fc3330a
#include <TinyGPS++.h>

TinyGPSPlus gps;

float gps_lat; //緯度
float gps_longt; //経度 

int RX_PIN = 33;
int TX_PIN = 32;

void setup()
{
  // シリアルポート開始
  Serial.begin(115200);
  Serial1.begin(9600, SERIAL_8N1, RX_PIN, TX_PIN);

}

void loop() {
  //Serial.println("test"); 
  while (Serial1.available() > 0) {
    char c = Serial1.read();
    gps.encode(c);
    if (gps.location.isUpdated()) {

      gps_lat = gps.location.lat();
      gps_longt = gps.location.lng();
      Serial.print("LAT:  "); Serial.println(gps_lat,9);
      Serial.print("LONG: "); Serial.println(gps_longt,9);
      delay(5000);
    }
  }
  delay(1000);
}
