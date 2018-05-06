#ifndef MOTORS_H
#define MOTORS_H

#include <Arduino.h>

//////////////////CONSTANT VARIABLES//////////////////

//Motors pins

const int motor1PinA = 10;
const int motor1PinB = 11;
const int motor2PinA = 5;
const int motor2PinB = 6;
const int enablePin = 12;

//Maximum and minimum values

#define throtMAX 110  //Maximum throttle
#define throtMIN 20	  //Minimum throttle
#define throtNOM 35	  //Nominal throttle	

////////////////CLASS DEFINITION///////////////////

class motor {

    int power, powerB;

  public:

    motor(int p=throtNOM) : power(p) {}  //Constructor of the class

    //Other methods
    void turnRight(); //turn right
    void turnLeft();  //turn left
    void ini();             //Initialite motors
    void stopm();            //stop motors
    void goStraight();      //Resume motors

};

#endif
