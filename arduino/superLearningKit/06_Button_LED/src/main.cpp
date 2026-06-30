#include <Arduino.h>

int LED_PIN = 11;
int IN_PIN = 7;
int val;

int state = HIGH;
int reading;
int previous = LOW;

unsigned long time = 0;
unsigned long debounce = 200UL; // UL means unsigned long

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(IN_PIN, INPUT);
  Serial.begin(9600);
}

// void loop() {
//   val = digitalRead(IN_PIN);
//   if (val == LOW){
//     digitalWrite(LED_PIN, LOW);
//   } else {
//     digitalWrite(LED_PIN, HIGH);
//   }
// }

void loop() {
  reading = digitalRead(IN_PIN);

  if (reading == HIGH && previous == LOW && millis() - time > debounce) {
    if (state == HIGH) {
      state = LOW;
      Serial.println("Low");
    } else {
      state = HIGH;
      Serial.println("High");
    }
    time = millis();
  }

  digitalWrite(LED_PIN, state);

  previous = reading;
}
