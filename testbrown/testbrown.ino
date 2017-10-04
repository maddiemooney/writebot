#include <Stepper.h>
 
const int stepsPerRevolution = 20; 
 
// Connection pins:
Stepper brown(stepsPerRevolution, 2,3,4,5);
 
void setup() {
 delay(100);
 brown.setSpeed(60);
 brown.step(200); 
 delay(100);
 
}
 
void loop() {
 
}
