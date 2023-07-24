#include <TM1637Display.h>

#define CLK 17
#define DIO 33

const uint8_t SEG_ABCD[] = {
  SEG_A | SEG_B | SEG_C | SEG_E | SEG_F | SEG_G,   // A
  SEG_F | SEG_E | SEG_D | SEG_C | SEG_G,           // b
  SEG_A | SEG_F | SEG_E | SEG_D ,                  // C
  SEG_B | SEG_C | SEG_D | SEG_E | SEG_G            // d
  };  
const uint8_t SEG_EFGH[] = {
  SEG_A | SEG_F | SEG_G | SEG_E | SEG_D,           // E  
  SEG_F | SEG_E | SEG_A | SEG_G,                   // F
  SEG_A | SEG_F | SEG_G | SEG_B | SEG_C | SEG_D,   // G
  SEG_C | SEG_G | SEG_E | SEG_F                    // h
  };
  const uint8_t SEG_IJKL[] = {  
  SEG_E | SEG_F,                                   // i    
  SEG_B | SEG_C | SEG_D | SEG_E,                   // J
  SEG_G | SEG_A | SEG_E | SEG_C | SEG_F,           // K 
  SEG_E | SEG_D | SEG_F                            // L
  };  
  const uint8_t SEG_MNOP[] = {
  SEG_A | SEG_B | SEG_C | SEG_E | SEG_F,           // M
  SEG_C | SEG_E | SEG_G,                           // N
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,   // O
  SEG_F | SEG_E | SEG_G | SEG_A | SEG_B            // P
  };
  const uint8_t SEG_QRST[] = {  
  SEG_A | SEG_B | SEG_C | SEG_G | SEG_F,           // q
  SEG_G | SEG_E,                                   // r     
  SEG_A | SEG_F | SEG_D | SEG_C | SEG_G,           // S  
  SEG_F | SEG_E | SEG_G | SEG_D                    // t
  };
  const uint8_t SEG_UVWX[] = {  
  SEG_E | SEG_D | SEG_C,                           // u
  SEG_F | SEG_E | SEG_C | SEG_D | SEG_B,           // V
  SEG_B | SEG_F | SEG_D,                           // W
  SEG_B | SEG_C | SEG_E | SEG_G | SEG_F            // x
  };
  const uint8_t SEG_YZ[] = {  
  SEG_F | SEG_G | SEG_B | SEG_C | SEG_D,           // Y
  SEG_A | SEG_B | SEG_E | SEG_D,                   // Z
  SEG_G,                                           // -
  SEG_G 
  };

TM1637Display display(CLK, DIO);
 
void setup() {
}
 
void loop() {
    display.setBrightness(0x0f);       
    display.setSegments(SEG_ABCD);    
    delay(3000);//setSegments
    display.setSegments(SEG_EFGH);    
    delay(3000);//setSegments
    display.setSegments(SEG_IJKL);    
    delay(3000);//setSegments
    display.setSegments(SEG_MNOP);    
    delay(3000);//setSegments
    display.setSegments(SEG_QRST);    
    delay(3000);//setSegments
    display.setSegments(SEG_UVWX);    
    delay(3000);//setSegments
    display.setSegments(SEG_YZ);
    delay(3000);//setSegments*/
 
}
