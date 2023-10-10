//Connect vibration sensor to IN connector
//Slide switch on the ESP32 dongle:3.3V.(Also 5.0V OK)

#define InputPin 32
int val;

void setup() {
  Serial.begin(115200);
  pinMode(InputPin,INPUT);
}

int SensAve(){
  int i;
  int sval=0;
  int ave=0;
  for (i = 0; i < 10000; i++){
    sval = sval + digitalRead(InputPin);
  }
  ave = sval / 100;
  return ave;
}

void loop() {
  val = SensAve();
  Serial.println(val);
}