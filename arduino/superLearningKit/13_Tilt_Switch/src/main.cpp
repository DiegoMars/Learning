#include <Arduino.h>

int ledPin = 8;
int potPin = 5;
int i;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  i = analogRead(potPin);
  if (i > 512) {
    digitalWrite(ledPin, LOW);
  } else {
    digitalWrite(ledPin, HIGH);
  }
}
