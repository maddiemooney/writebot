#include <Servo.h>

int servoPin = 6;

Servo zAxis;

int servoAngle = 0;

void setup() {
  Serial.begin(9600);
  zAxis.attach(servoPin);
}

void loop() {
  //move pen down
  for(servoAngle = 0; servoAngle <45; servoAngle++) {
    zAxis.write(servoAngle);
    delay(50);
  }

  /*for(servoAngle = 45; servoAngle >0; servoAngle--) {
    zAxis.write(-servoAngle);
    delay(50);
  }*/
  
  //move pen up
  /*for(servoAngle = 180; servoAngle >0; servoAngle--) {
    zAxis.write(servoAngle);
    delay(10);
  }*/
}


