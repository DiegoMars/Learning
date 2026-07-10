#include <Arduino.h>

// Method 1
// int servopin = 9;
// int myangle;
// int pulsewidth;
// int val;
//
// void servopulse(int servopin, int myangle) { // pulse function
//   pulsewidth = (myangle * 11) + 500;
//   digitalWrite(servopin, HIGH);
//   delayMicroseconds(pulsewidth);
//   digitalWrite(servopin, LOW);
//   delay(20 - pulsewidth / 1000);
// }
//
// void setup() {
//   pinMode(servopin, OUTPUT);
//   Serial.begin(9600);
//   Serial.println("servo = o_seral_simple ready");
// }
//
// // Convert numbers 0 - 9 to a corresponding 0 - 180 degree angle, mentions that the LED will blink
// // for the number of times but no idea how they acheive that here.
// void loop() {
//   val = Serial.read();
//   if (val >= '0' && val <= '9') { // Convert to number
//     val = val - '0';
//     val = val * (180/9);
//     Serial.print("moving servo to ");
//     Serial.print(val, DEC);
//     Serial.println();
//     for (int i = 0; i <= 50; i++) { // Give time for servo to rotate
//       servopulse(servopin, val); // Use the pulse function
//     }
//   }
// }

// Method 2
#include <Servo.h>

Servo myservo; // defines servo name

void setup() {
  myservo.attach(9);
}

void loop() {
  myservo.write(90);
}
