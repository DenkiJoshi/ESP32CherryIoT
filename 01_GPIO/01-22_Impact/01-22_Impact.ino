#define imp_pin 33 //INA:33 INB:15
#define led_pin 13 //OUTA:26 OUTB:13
int val;

void setup() {
  Serial.begin(115200);
  pinMode(imp_pin,INPUT);
  pinMode(led_pin,OUTPUT);
}

int SensAve(){
  int i;
  int sval=0;
  int ave=0;
  for (i = 0; i < 10000; i++){
    sval = sval + digitalRead(imp_pin);  // アナログ入力ピンのセンサから
  }
  ave = sval / 100;
  return ave;
}

void loop() {
  val = SensAve();
  Serial.println(val);
  if(val>0 && val<90) //val<xxのxxが感度。0～100
  {
    digitalWrite(led_pin,LOW);
  }
  else{
    digitalWrite(led_pin,HIGH);
  }
}
