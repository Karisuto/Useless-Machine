#include <Servo.h> 
int lidServoPin = 3;
int armServoPin = 1;
Servo lidServo; 
Servo armServo;

void setup() {
  lidServo.attach(lidServoPin);
  armServo.attach(armServoPin); 
}
 
void loop() {
  lidServo.write(75);
  armServo.write(0);
  delay(1000);
  lidServo.write(0);
  armServo.write(100);
  delay(1000);
}
