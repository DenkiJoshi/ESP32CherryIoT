#include <TM1637Display.h>

#define CLK 17  //OUTA:27 OUTB:4
#define DIO 33 //OUTA:26 OUTB:13

int numCounter = 0;
 
TM1637Display display(CLK, DIO); //set up the 4-Digit Display.
 
void setup()
{
  display.setBrightness(0x0a); //set the diplay to maximum brightness
}
 
void loop()
{
  for(numCounter = 0; numCounter < 100; numCounter++) //Iterate numCounter
  {
    display.showNumberDec(numCounter); //Display the numCounter value;
    delay(200);
  }
}
