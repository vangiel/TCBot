#include "motors.h"


void motor::ini(){
	
  // set all the other pins you're using as outputs:
  pinMode(motor1PinA, OUTPUT);
  pinMode(motor1PinB, OUTPUT);
  pinMode(motor2PinA, OUTPUT);
  pinMode(motor2PinB, OUTPUT);

  pinMode(enablePin, OUTPUT);
}

void motor::stop(){

  //Reset motors:
  analogWrite(motor1PinA, 0);
  analogWrite(motor2PinA, 0);
  analogWrite(motor1PinB, 0);
  analogWrite(motor2PinB, 0);

  // set up the enable pin to LOW (not enable):
  digitalWrite(enablePin, LOW);
}

void motor::goStraight(){
  // set up the enable pin to HIGH(enable):
  digitalWrite(enablePin, HIGH);

  //Go straight:
  analogWrite(motor1PinA, power);
  analogWrite(motor2PinA, power);
  analogWrite(motor1PinB, 0);
  analogWrite(motor2PinB, 0);
}

void motor::turn::right(){
  // set up the enable pin to HIGH(enable):
  digitalWrite(enablePin, HIGH);

  //Go right:
  analogWrite(motor1PinA, power);
  analogWrite(motor2PinA, 0);
  analogWrite(motor1PinB, 0);
  analogWrite(motor2PinB, 0);
}

void motor::turn::left(){
  // set up the enable pin to HIGH(enable):
  digitalWrite(enablePin, HIGH);

  //Go straight:
  analogWrite(motor1PinA, 0);
  analogWrite(motor2PinA, power);
  analogWrite(motor1PinB, 0);
  analogWrite(motor2PinB, 0);
}
