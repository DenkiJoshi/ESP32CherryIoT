#include "KT403A_Player.h"  // Seeed Serial MP3 Player by Seeed Studio

const int mp3RxPin = 3;  // 3: Connector A, 4: Connector B
const int mp3TxPin = 1;  // 1: Connector A, 5: Connector B

HardwareSerial mp3Serial(1);
KT403A<HardwareSerial> mp3Player;

void setup() {
  Serial.begin(115200);
  mp3Serial.begin(9600, SERIAL_8N1, mp3RxPin, mp3TxPin);   // Start serial communication with the MP3 player
  delay(1000);
  mp3Player.init(mp3Serial);    // Initialize the MP3 player
  delay(500);
  mp3Player.playSongMP3(1);  // Play /MP3/0001.mp3
}

void loop() {
}