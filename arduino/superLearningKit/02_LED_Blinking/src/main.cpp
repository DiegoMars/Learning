#include <Arduino.h>

int LED_PIN = 10; // define digital pin 10

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH); // Set LED on
  delay(1000);
  digitalWrite(LED_PIN, LOW); // Set LED off
  delay(1000);
}
