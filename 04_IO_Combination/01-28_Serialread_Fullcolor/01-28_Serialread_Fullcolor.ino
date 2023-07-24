#define red 27
#define green 25
#define blue 26

void setup(){
  Serial.begin(115200);
  pinMode(red, OUTPUT); 
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT); 

  digitalWrite(red, HIGH); 
  digitalWrite(green, HIGH);
  digitalWrite(blue, HIGH); 
}

void loop() {
  String str = Serial.readStringUntil('\r');

  if ( str == "r"){
    digitalWrite(red, LOW); 
  }
  else if ( str == "g") {
    digitalWrite(green, LOW); 
  }
  else if ( str == "b") {
    digitalWrite(blue, LOW); 
  }
  else {
    digitalWrite(red, HIGH); 
    digitalWrite(green, HIGH);
    digitalWrite(blue, HIGH); 
  }  
}
