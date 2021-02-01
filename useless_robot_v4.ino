#include <Servo.h> 
int switchPin = D7;
int lidServoPin = D3;
int armServoPin = D4;
int action = 1;
int pos = 0;

//Servo position values 
int buttonPress = 60;
int almostPress = 65;
int armRetract = 180;
int lidClose = 90;
int lidOpen = 40;
int lidSpeed = 50;
int shortPause = 100; //100 milliseconds
int halfSecondPause = 500; //half second
int secondPause = 1000; //one second

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
 
void loop(){
  if(digitalRead(switchPin) == HIGH){
    Serial.println("ON");

    //restart action sequence
    if(action > 8) {
      action = 1;
    }
      if(action == 1){
        action1();
      }
      else if (action == 2) {
        action2();
      }
      else if (action == 3) {
        action3();
      }
      else if (action == 4) {
        action4();
      }
      else if (action == 5) {
        action5();
      }
      else if (action == 6) {
        action6();
      }
      else if (action == 7) {
        action7();
      }
      else if (action == 8) {
        action8();
      }
      //moves onto next action
      action += 1;
  }
  else{
    armServo.write(armRetract);
    lidServo.write(lidClose);
    delay(1000);
    Serial.println("OFF");
    
  }
}

void lidOpenSlow(){
  for(pos = lidClose; pos > lidOpen; pos -=1)
  {
    lidServo.write(pos);
    delay(lidSpeed);
  }
  yr
}


void lidCloseSlow (){
  for(pos = lidOpen; pos > lidClose; pos +=1)
  {
    lidServo.write(pos);
    delay(lidSpeed);
  }
  
}
/*
int buttonPress = 100;
int almostPress = 80;
int armRetract = 0;
int lidClose = 90;
int shortPause = 100; //100 milliseconds
int halfSecondPause = 500; //half second
int oneSecondPause = 1000; //one second
 */

 //individual action sequences

void action1()
{
  Serial.println("1");
  lidServo.write(lidOpen);
  delay(secondPause);
  armServo.write(buttonPress);
  delay(halfSecondPause); 
  armServo.write(armRetract);
  delay(secondPause);
  lidServo.write(lidClose);
  delay(secondPause);
}

void action2(){
  Serial.println("2");
  lidServo.write(lidOpen);
  delay(shortPause);
  armServo.write(buttonPress);
  delay(halfSecondPause);
  armServo.write(armRetract);
  delay(shortPause);
  lidCloseSlow();
}

void action3(){
  Serial.println("3");
  lidOpenSlow();
  delay(shortPause);
  armServo.write(buttonPress);
  delay(shortPause);
  armServo.write(armRetract);
  delay(shortPause);
  lidServo.write(lidClose);
}

void action4()
{
  Serial.println("4");
  delay(secondPause);
  lidServo.write(lidOpen);
  delay(shortPause);
  armServo.write(buttonPress);
  delay(secondPause);
  armServo.write(armRetract);
  lidCloseSlow();
}


void action5()
{
  lidServo.write(lidOpen);
  delay(500);
  lidServo.write(lidClose);
  delay(500);
  lidServo.write(lidOpen);
  delay(500);
  lidServo.write(lidClose);
  delay(500);
  lidServo.write(lidOpen);
  delay(500);
  lidServo.write(lidClose);
  delay(2500);
  lidServo.write(lidOpen);
  delay(100);
  armServo.write(buttonPress);
  delay(250);
  armServo.write(armRetract);
  delay(100);
  lidServo.write(lidClose);
}

void action6()
{
  lidServo.write(lidOpen);
  delay(100);
  armServo.write(almostPress);
  delay(250);
  armServo.write(armRetract);
  delay(100);
  lidServo.write(lidClose);
  delay(250);
  lidServo.write(lidOpen);
  delay(100);
  armServo.write(almostPress);
  delay(250);
  armServo.write(armRetract);
  delay(100);
  lidServo.write(lidClose);
  delay(250);
  lidServo.write(lidOpen);
  delay(100);
  armServo.write(almostPress);
  delay(250);
  armServo.write(armRetract);
  delay(100);
  lidServo.write(lidClose);
  delay(250);  
  lidServo.write(lidOpen);
  delay(100);
  armServo.write(buttonPress);
  delay(250);
  armServo.write(armRetract);
  delay(100);
  lidServo.write(lidClose);
}

void action7()
{
  Serial.println("7");
  lidOpenSlow();
  delay (100);
  lidCloseSlow();
}

void action8()
{
 Serial.println("8");
 lidOpenSlow();
 delay(shortPause);
 armServo.write(almostPress);
 delay(halfSecondPause);
 armServo.write(armRetract);
 delay(shortPause);
 lidCloseSlow();
 delay(secondPause);
 lidServo.write(lidOpen);
 
}
