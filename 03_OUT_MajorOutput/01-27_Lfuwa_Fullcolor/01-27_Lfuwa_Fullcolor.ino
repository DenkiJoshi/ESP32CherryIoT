#define red 27 
#define green 26
#define blue 25

void setup(){
  // 使用するタイマーのチャネル,周波数,デューティ比を設定
  ledcSetup(0, 12800, 8);
  ledcSetup(1, 12800, 8);
  ledcSetup(2, 12800, 8);
  // 各色を各チャネルへ接続
  ledcAttachPin(red, 0);
  ledcAttachPin(green, 1);
  ledcAttachPin(blue, 2);
}
void loop() {
  for (int i=0; i<256; i++){ 
   ledcWrite(0, i);
   ledcWrite(1, 0);
   ledcWrite(2, 255-i);
   delay(10);
  }
  for (int i=0; i<256; i++){ 
   ledcWrite(0, 255-i);
   ledcWrite(1, i);
   ledcWrite(2, 0);
   delay(10);
  }
  for (int i=0; i<256; i++){ 
   ledcWrite(0, 0);
   ledcWrite(1, 255-i);
   ledcWrite(2, i);
   delay(10);
  }
}
