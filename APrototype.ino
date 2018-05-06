
#include "motors.h"
#include "sensors.h"

//Objects creations

motor tmotor(42);
sensor tsensor;
ledRGB tledRGB;

//Other variables

void setup() {

  tmotor.ini();
  tmotor.stopm();
  tledRGB.ini();

  //  Serial.begin(9600); // start the serial port

}

void loop() {

  tsensor.readSensors();

  //  Serial.print(analogRead(edgeL));
  //  Serial.print(" | ");
  //  Serial.println(analogRead(edgeR));
  //  delay(500);

  if (tsensor.dr > edgeThreshold || tsensor.dl > edgeThreshold || ((tsensor.distance <= 25) && (tsensor.distance > 10))) {
    if (tsensor.dr > edgeThreshold) {
      tmotor.turnLeft();
    }
    if (tsensor.dl > edgeThreshold) {
      tmotor.turnRight();
    }
    if ((tsensor.distance <= 25) && (tsensor.distance > 10)) {
      tmotor.turnLeft();
      delay(1300);
    }
  }
  else {
    tmotor.goStraight();
  }
}

