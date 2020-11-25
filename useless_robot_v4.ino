#include <Servo.h> 
int switchPin = D7;
int lidServoPin = D3;
int armServoPin = D4;
int action = 1;
int pos = 0;

//Servo position values 
int buttonPress = 100;
int almostPress = 80;
int armRetract = 0;
int lidClose = 90;

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
  
}


void lidCloseSlow (){
  for(pos = lidOpen; pos > lidClose; pos +=1)
  {
    lidServo.write(pos);
    delay(lidSpeed);
  }
  
}
/*
  
  buttonPress = 100;
  almostPress = 80;
  armRetract = 0;
  lidClose = 90;
  lidOpen = 20;
  lidSpeed = 50; 

 */

 //individual action sequences

void action1(){
  Serial.println("1");
  lidServo.write(20);
  delay(1000);
  armServo.write(buttonPress);
  delay(500); 
  armServo.write(armRetract);
  delay(1000);
  lidServo.write(lidClose);
  delay(1000);
}

void action2(){
  Serial.println("2");
  lidServo.write(50);
  delay(100);
  armServo.write(buttonPress);
  delay(250);
  armServo.write(armRetract);
  delay(100);
  lidServo.write(lidClose);
}

void action3(){
  Serial.println("3");
  for(pos = 90; pos > 20; pos -=1)
  {
    lidServo.write(pos);
    delay(50);
  }
  armservo.write(buttonPress);
  delay(250);
  armservo.write(armRetract);
  delay(100);
  lidservo.write(lidClose);
}

void action4(){
  Serial.println("4");
  delay(250);
  lidservo.write(50);
  delay(100);
  armservo.write(buttonPress);
  delay(2500);
  lidOpenSlow();
  lidservo.write(lidClose);
  armservo.write(armRetract);
}
}

void action5(){
  lidservo.write(50);
  delay(500);
  lidservo.write(lidClose);
  delay(500);
  lidservo.write(50);
  delay(500);
  lidservo.write(lidClose);
  delay(500);
  lidservo.write(50);
  delay(500);
  lidservo.write(lidClose);
  delay(2500);
  lidservo.write(50);
  delay(100);
  armservo.write(buttonPress);
  delay(250);
  armservo.write(armRetract);
  delay(100);
  lidservo.write(lidClose);
}

void action6(){
  lidservo.write(50);
  delay(100);
  armservo.write(almostPress);
  delay(250);
  armservo.write(armRetract);
  delay(100);
  lidservo.write(lidClose);
  delay(250);
  lidservo.write(50);
  delay(100);
  armservo.write(almostPress);
  delay(250);
  armservo.write(armRetract);
  delay(100);
  lidservo.write(lidClose);
  delay(250);
  lidservo.write(50);
  delay(100);
  armservo.write(almostPress);
  delay(250);
  armservo.write(armRetract);
  delay(100);
  lidservo.write(lidClose);
  delay(250);  
  lidservo.write(50);
  delay(100);
  armservo.write(buttonPress);
  delay(250);
  armservo.write(armRetract);
  delay(100);
  lidservo.write(lidClose);
}

void action7(){
  Serial.println("7");
  lidOpenSlow();
  delay (100);
  lidCloseSlow();
}

void action8(){
 Serial.println("8");
 lidOpenSlow();
 delay(100);
 lidCloseSlow();




}
