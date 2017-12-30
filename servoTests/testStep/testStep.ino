#include <Stepper.h>

int teststep = 20; /*maybe change*/

//hey hey pins
//Stepper testStepper(teststep, 2,3,4,5);
Stepper testStepper(teststep, 5,4,3,2);

void setup() {
  // put your setup code here, to run once:
  testStepper.setSpeed(500);
  testStepper.step(1000);
  delay(1000);
  testStepper.step(-1000);

}

void loop() {
  // put your main code here, to run repeatedly:
  
}
