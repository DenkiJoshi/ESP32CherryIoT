#define LED_Pin 13 //OUTA26 OUTB13
#define SW_Pin 33 //INA33 INB32
volatile int state = LOW;
 
void setup() {
  pinMode(SW_Pin, INPUT_PULLUP);
  pinMode(LED_Pin, OUTPUT);
  attachInterrupt(SW_Pin, LED_blink, RISING);
}

void loop() {
  digitalWrite(LED_Pin, state);
}

void LED_blink(){
  state = !state;
}
