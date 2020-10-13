#include <Servo.h> 
int switchPin = D7;
int lidServoPin = D3;
int armServoPin = D4;
Servo lidServo; 
Servo armServo;

void setup() {
  Serial.begin(9600);
  Serial.println("Waiting for Toggle Switch...");
  
  pinMode(switchPin, INPUT);
  lidServo.attach(lidServoPin);
  armServo.attach(armServoPin);

  //Servo Default Starting Positions

  //armServo.write(0);
  //lidServo.write(0);
}
 
void loop() {
  if(digitalRead(switchPin) == HIGH){
    Serial.println("ON");
    lidServo.write(75);
    armServo.write(0);
    delay(1000);
    lidServo.write(0);
    armServo.write(100);
    delay(1000);
    //delay(500);
  }
  else{
    Serial.println("OFF");
    //delay(500);
  }
}
