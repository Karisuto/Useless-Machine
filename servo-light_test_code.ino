#include <Servo.h> 
int servoPin = 3; 
int ledPin = 5;
Servo Servo1; 


void setup() {
  pinMode(ledPin, OUTPUT);
  Servo1.attach(servoPin); 
}
 
void loop() {
  digitalWrite(ledPin, HIGH);
  Servo1.write(0); 
  delay(1000);
  digitalWrite(ledPin, LOW);
  Servo1.write(90);
  delay(1000);
}
