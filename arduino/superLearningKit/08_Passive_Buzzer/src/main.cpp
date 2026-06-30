#include <Arduino.h>

int buzzer = 8;

void setup() {
  pinMode(buzzer, OUTPUT);
}

void loop() {
  unsigned char i, j; // An 8 bit number, ranging from 0 to 255
  while (true) {
    for (i = 0; i < 80; i++) {
      digitalWrite(buzzer, HIGH);
      delay(1);
      digitalWrite(buzzer, LOW);
      delay(1);
    }
    for (i = 0; i < 100; i++) {
      digitalWrite(buzzer, HIGH);
      delay(2);
      digitalWrite(buzzer, LOW);
      delay(2);
    }
  }
}

// Interesting lil project
