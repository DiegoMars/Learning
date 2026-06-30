#include <Arduino.h>

int redPin = 11;
int greenPin = 10;
int bluePin = 9;

int val;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  for (val = 255; val > 0; val--) {
    analogWrite(11, val);
    analogWrite(10, 255-val);
    analogWrite(9, 128-val);
    delay(1);
  }
  for (val = 0; val < 255; val++) {
    analogWrite(11, val);
    analogWrite(10, 255-val);
    analogWrite(9, 128-val);
    delay(1);
  }
  Serial.println(val, DEC); // Print in decimal form
}
