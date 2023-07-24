#include <TM1637Display.h>

#define CLK 17
#define DIO 33

TM1637Display display(CLK, DIO);
 
void setup() {
}
 
void loop() {
    display.setBrightness(0x0f);
    display.showNumberDecEx(1435,0x0,true);
    delay(1000);
    display.showNumberHexEx(0xf1af); //16進数表現できるもののみ。
    delay(1000);
}
