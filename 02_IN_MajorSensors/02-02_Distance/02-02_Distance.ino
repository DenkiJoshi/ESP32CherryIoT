#include <Ultrasonic.h> //Grove Ultrasonic Ranger by Seeed Studio

Ultrasonic ultrasonic(32);

void setup() {
    Serial.begin(115200);
}
void loop() {
    long RangeInCentimeters;

    RangeInCentimeters = ultrasonic.MeasureInCentimeters(); // two measurements should keep an interval
    Serial.print(RangeInCentimeters);//0~400cm
    Serial.println(" cm");
    delay(250);
}
