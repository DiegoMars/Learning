#include <Arduino.h>

int potPin = 0;
int val;
int dat;
String print;

void setup() {
  Serial.begin(9600);
}

void loop() {
  val = analogRead(potPin);
  dat = (125 * val) >> 8; // Bitwise shift right by 8, basically dividing by 2 every shift, or dividing by 256
  Serial.print("Tep: ");
  Serial.print(dat);
  Serial.println(" C");
  delay(500);
}
