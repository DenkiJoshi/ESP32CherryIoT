#include <Wire.h>
#include <SSD1306.h> //「ESP8266 and ESP32 OLED driver for SSD1306 displays」をインストール

SSD1306  display(0x3c, 4, 13); //OUTA:0x3c,27,26 OUTB:0x3c,4,13
 
void setup() {
  display.init();    //ディスプレイを初期化
  display.setFont(ArialMT_Plain_24);    //フォントを設定
  display.drawString(0, 0, "Hello World");    //(0,0)の位置にHello Worldを表示
  display.display();   //指定された情報を描画
}
 
void loop() {}
