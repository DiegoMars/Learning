#include <Arduino.h>

int BASE = 2;
int NUM = 5;

void setup() {
  for (int pin = BASE; pin < BASE + NUM; pin++) {
    pinMode(pin, OUTPUT);
  }
}

void loop() {
  for (int pin = BASE; pin < BASE + NUM; pin++) {
    digitalWrite(pin, LOW);
    delay(50);
  }
  for (int pin = BASE; pin < BASE + NUM; pin++) {
    digitalWrite(pin, HIGH);
    delay(50);
  }
}
