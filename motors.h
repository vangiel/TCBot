#ifndef MOTORS_H
#define MOTORS_H

#include <Arduino.h>

//////////////////CONSTANT VARIABLES//////////////////

//Motors pins

#define motor1PinA 10
#define motor1PinB 11
#define motor2PinA 5
#define motor2PinB 6
#define enablePin 12

//Maximum and minimum values

#define throtMAX 110  //Maximum throttle
#define throtMIN 20	  //Minimum throttle
#define throtNOM 35	  //Nominal throttle	

////////////////CLASS DEFINITION///////////////////

class motor{
	class turn{
  		public:
  			friend class motor;
  			void right(); //turn right
  			void left();  //turn left
  	};

  protected:
    static int power;

  public:

  	void ini(); //Initialite motors
    void stop(); //stop motors
    void goStraight(); //Resume motors
    //motor(static int p){power = p;} //Constructor
};

#endif
