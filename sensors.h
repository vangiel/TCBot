#ifndef SENSORS_H
#define SENSORS_H

#include <Arduino.h>

//////////////////CONSTANT VARIABLES//////////////////

//LED RGB
const int LEDB = 2;
const int LEDR = 3;
const int LEDG = 4;

//Sensors
const int sensorFront = A1; //Read SHARP IR sensor
const int edgeR = A5;     //Read Right edge IR sensor
const int edgeL = A4;     //Read Left edge IR sensor

#define edgeThreshold 900

////////////////CLASS DEFINITION///////////////////

class sensor { 
    float volts = 0.0; //Volts measured by the sensor 
    
  public: 
    int distance, dl, dr; //Distance measured by the sensor
    void readSensors();


};

class ledRGB {

  public:
    void allOff();
    void blue();
    void green();
    void red();
};

#endif
