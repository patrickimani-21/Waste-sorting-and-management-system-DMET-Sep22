#include <Servo.h>

Servo servo1, servo2, servo3;

void setup() {
  servo1.attach(11);
  servo2.attach(5);
  servo3.attach(6);
  pinMode(9, OUTPUT);  // TRIG
  pinMode(10, INPUT);  // ECHO
  pinMode(4, INPUT_PULLUP); // Reed
  pinMode(3, INPUT);  // IR
  pinMode(8, OUTPUT); // Relay
  Serial.begin(9600);
}

void loop() {
  // Simplified simulation logic
  if (digitalRead(4) == LOW) {
    Serial.println("Magnetic detected");
    servo1.write(180);
    delay(1000);
    servo1.write(0);
  }
  
  // Ultrasonic simulation
  digitalWrite(9, HIGH);
  delayMicroseconds(10);
  digitalWrite(9, LOW);
  long dur = pulseIn(10, HIGH);
  if (dur > 0 && dur < 2000) {  // Adjusted for simulation
    Serial.println("Ultrasonic detected");
    servo2.write(180);
    delay(1000);
    servo2.write(0);
  }
  
  // IR simulation
  if (analogRead(3) < 500) {
    Serial.println("IR detected");
    servo3.write(180);
    delay(1000);
    servo3.write(0);
  }
  
  delay(100);
}
