#include "sensors.h"

/////////////SENSOR CLASS DEFINITIONS//////////////////

void sensor::readSensors() {

  //Read edge sensors
  dr = analogRead(edgeR);
  dl = analogRead(edgeL);

  //Read the IR sensor:
  volts = analogRead(sensorFront) * 0.0048828125; // value from sensor * (5/1024)
  distance = 13 * pow(volts, -1); // worked out from datasheet graph
  delay(1); // slow down
}


/////////////LEDRGB CLASS DEFINITIONS//////////////////

void ledRGB::allOff() {
  digitalWrite(LEDR, LOW);
  digitalWrite(LEDG, LOW);
  digitalWrite(LEDB, LOW);
}

void ledRGB::blue() {
  digitalWrite(LEDR, LOW);
  digitalWrite(LEDG, HIGH);
  digitalWrite(LEDB, LOW);
}

void ledRGB::green() {
  digitalWrite(LEDR, LOW);
  digitalWrite(LEDG, HIGH);
  digitalWrite(LEDB, LOW);
}

void ledRGB::red() {
  digitalWrite(LEDR, HIGH);
  digitalWrite(LEDG, LOW);
  digitalWrite(LEDB, LOW);
}

