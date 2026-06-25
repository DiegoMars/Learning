#include <Arduino.h>

int LED_PIN = 11;
int IN_PIN = 7;
int val;
bool pressed;
bool on;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(IN_PIN, INPUT);
}

void loop() {
  val = digitalRead(IN_PIN);
  if (val == HIGH) {
    if (pressed) {
      pressed = false;
    } else {
      pressed = true;
    }
  } else {
    if (pressed) {
      digitalWrite(LED_PIN, HIGH);
    } else {
      digitalWrite(LED_PIN, LOW);
    }
  }
}
