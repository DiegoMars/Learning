#include <Arduino.h>

int LED_PIN = 11;
int IN_PIN = 7;
int val;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(IN_PIN, INPUT);
}

void loop() {
  val = digitalRead(IN_PIN);
  if (val == LOW){
    digitalWrite(LED_PIN, LOW);
  } else {
    digitalWrite(LED_PIN, HIGH);
  }
}
