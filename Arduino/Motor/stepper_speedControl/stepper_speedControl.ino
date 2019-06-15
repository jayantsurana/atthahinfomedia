#include <Stepper.h>

const int stepsPerRevolution = 200;

Stepper myStepper(stepsPerRevolution, 9, 10, 11, 12);

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorReading = analogRead(A1);
  int motorSpeed = map(sensorReading, 0, 1023, 0, 100);

  Serial.println(sensorReading);
  Serial.println(motorSpeed);
  
  if (motorSpeed > 0) {
    myStepper.setSpeed(motorSpeed);
    myStepper.step(stepsPerRevolution / 100);
  }
}
