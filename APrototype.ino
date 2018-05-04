
#include "motors.h"
//LED RGB
const int LEDB = 2;
const int LEDR = 3;
const int LEDG = 4;

//Sensors
const int sensorPin = A1; //Read SHARP IR sensor
const int edgeR = A5;     //Read Right edge IR sensor
const int edgeL = A4;     //Read Left edge IR sensor

motor tmotor;

//Other variables
int power1, power2;    // store the value given to the PWM
int distance, dl, dr; //Distance measured by the sensor
float volts = 0.0; //Volts measured by the sensor

void setup() {

  digitalWrite(LEDR, HIGH);
  digitalWrite(LEDG, LOW);
  digitalWrite(LEDB, LOW);

  tmotor.ini();
  tmotor.stop();

  Serial.begin(9600); // start the serial port

}

void loop() {

  // Read the IR sensor:
  volts = analogRead(sensorPin)*0.0048828125;  // value from sensor * (5/1024)
  distance = 13*pow(volts, -1); // worked out from datasheet graph
  delay(1); // slow down 
  
  //power = map(analogRead(sensorPin),0,30,0,255);
  power1 = 40;

  //read edge sensors
  dr=analogRead(edgeR);
  dl=analogRead(edgeL);
  
  digitalWrite(enablePin, HIGH);
  analogWrite(motor1PinA, power1);
  analogWrite(motor1PinB, 0);    
  analogWrite(motor2PinA, power1);
  analogWrite(motor2PinB, 0);

//  Serial.print(analogRead(edgeL));
//  Serial.print(" | ");
//  Serial.println(analogRead(edgeR));
//  delay(500);

  if (dr>900){
    analogWrite(motor1PinA, power1);
    analogWrite(motor1PinB, 0);    
    analogWrite(motor2PinA, 0);
    analogWrite(motor2PinB, 0);
  }
//  if ((distance <= 25) && (distance > 10))
//  {    
//    // if the switch is high, motor will turn on one direction:
//    analogWrite(motor1PinA, power1);
//    analogWrite(motor1PinB, 0);    
//    analogWrite(motor2PinA, 0);
//    analogWrite(motor2PinB, 0);
//  }
}

