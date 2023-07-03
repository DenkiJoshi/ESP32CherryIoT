// serial_voltage_byte_sample1

#define press_pin 32 //INA:33 INB:32

float ain,vo,rf;

void setup() {
  Serial.begin(115200);
  pinMode(press_pin, INPUT);
}

void loop() {
  ain = analogRead(press_pin);
  vo = ain * 3.3 / 4096;
  rf = 10000 * vo / (3.3 - vo);
  Serial.print( rf );
  Serial.println( "g" );
  delay( 1000 );
}
