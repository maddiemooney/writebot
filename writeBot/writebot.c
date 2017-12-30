/* written by Maddie Mooney
 * 
 * Jan 10: adding z axis servo
 * Jan 18: changing angles and speed
 * Jan 29: adding serial port access (hopefully)
 * Feb 01: more serial port
 * 
 */

#include <Servo.h>

int zAxisPin = 6;
Servo zAxis;
int zAxisAngle = 0;

//pen up/down function
void penDown();
void penUp();

//stepper library

 //x axis
 //sort of out of order here sorry, but each servo/axis  has 4 pins
 int xcoil1a = 2;
 int xcoil1b = 5;
 int xcoil2a = 3;
 int xcoil2b = 4;

 //y axis
 int ycoil1a = 8;
 int ycoil1b = 11;
 int ycoil2a = 9; 
 int ycoil2b = 10; 

 void xStepPatternForward(int xNumberOfStepsf);
 void xStepPatternBackward(int xNumberOfStepsb);

 void yStepPatternForward(int yNumberOfStepsf);
 void yStepPatternBackward(int yNumberOfStepsb);

 //letter definitions
 void A();
 void B();
 void C();
 void D();
 void E();
 void FF(); //defined as FF because Arduino has a builtin F(); oops
 void G();
 void H();
 void I();
 void J();
 void K();
 void L();
 void M();
 void N();
 void O();
 void P();
 void Q();
 void R();
 void S();
 void T();
 void U();
 void V();
 void W();
 void X();
 void Y();
 void Z();
 void space();

void setup() {
  // opening serial port
  Serial.begin(9600);
  //pinMode(13, OUTPUT); //test for serial
  Serial.write('1'); //tells python hello i am ready
  // connecting servo
  zAxis.attach(zAxisPin);
  // stepper library pinModes
  pinMode(xcoil1a, OUTPUT);
  pinMode(xcoil1b, OUTPUT);
  pinMode(xcoil2a, OUTPUT);
  pinMode(xcoil2b, OUTPUT);

  pinMode(ycoil1a, OUTPUT);
  pinMode(ycoil1b, OUTPUT);
  pinMode(ycoil2a, OUTPUT);
  pinMode(ycoil2b, OUTPUT);
}

void penDown() {
  int zAxisAngle = 0;

  for(zAxisAngle = 0; zAxisAngle <45; zAxisAngle++) {
    zAxis.write(zAxisAngle); //makes it go ccw 45 degrees
    delay(25); //change for different speeds
  }
}

void penUp() {
  int zAxisAngle = 45;

  for(zAxisAngle = 45; zAxisAngle >0; zAxisAngle--) {
    zAxis.write(zAxisAngle); //goes cw 45 degrees
    delay(25); //change for different speeds
  }
}

//this next part *should* be rewritten as an importable library
/* Jan 11: changed port info
 * Jan 18: uh. changed a LOT. 
 * Jan 18: combined files now this is in writebot 
 * 
 * the steps listed below are for half steps, so instead of 4 steps,
 * there's 8.
 * 
 * for the motor to go forward, do steps 1->8, for backward, do
 * steps 8->1. this is coded in functions *stepPatternForward and
 * *stepPatternBackward
 * 
 * step | coil 1a | coil 1b | coil 2a | coil 2b
 * ---- | ------- | ------- | ------- | --------
 * 1    | LOW     | HIGH    | LOW     | HIGH
 * 2    | LOW     | LOW     | LOW     | HIGH
 * 3    | HIGH    | LOW     | LOW     | HIGH
 * 4    | HIGH    | LOW     | LOW     | LOW
 * 5    | HIGH    | LOW     | HIGH    | LOW
 * 6    | LOW     | LOW     | HIGH    | LOW
 * 7    | LOW     | HIGH    | HIGH    | LOW
 * 8    | LOW     | HIGH    | LOW     | LOW
 * 
 * thinking about this more, it's likely that i'll have to have two of these
 * functions, one for each stepper motor. so these functions will be 
 * xStepPatternForward, xStepPatternBackward, yStepPatternForward, and 
 * yStepPatternBackward. 
 * 
 * 
 */

void xStepPatternForward(int xNumberOfStepsf) { //towards glass

  for (int times = 0; times < xNumberOfStepsf; times++) {
    // step 1
    digitalWrite(xcoil1a, LOW);
    digitalWrite(xcoil1b, HIGH);
    digitalWrite(xcoil2a, LOW);
    digitalWrite(xcoil2b, HIGH);

    delay(20); //delays included for testing, may get rid of or decrease
    
    // step 2
    digitalWrite(xcoil1a, LOW);
    digitalWrite(xcoil1b, LOW);
    digitalWrite(xcoil2a, LOW);
    digitalWrite(xcoil2b, HIGH);

    delay(20);
    
    // step 3
    digitalWrite(xcoil1a, HIGH);
    digitalWrite(xcoil1b, LOW);
    digitalWrite(xcoil2a, LOW);
    digitalWrite(xcoil2b, HIGH);

    delay(20);
    
    // step 4
    digitalWrite(xcoil1a, HIGH);
    digitalWrite(xcoil1b, LOW);
    digitalWrite(xcoil2a, LOW);
    digitalWrite(xcoil2b, LOW);

    delay(20);
    
    // step 5
    digitalWrite(xcoil1a, HIGH);
    digitalWrite(xcoil1b, LOW);
    digitalWrite(xcoil2a, HIGH);
    digitalWrite(xcoil2b, LOW);

    delay(20);
    
    // step 6
    digitalWrite(xcoil1a, LOW);
    digitalWrite(xcoil1b, LOW);
    digitalWrite(xcoil2a, HIGH);
    digitalWrite(xcoil2b, LOW);

    delay(20);
    
    // step 7
    digitalWrite(xcoil1a, LOW);
    digitalWrite(xcoil1b, HIGH);
    digitalWrite(xcoil2a, HIGH);
    digitalWrite(xcoil2b, LOW);

    delay(20);

    // step 8
    digitalWrite(xcoil1a, LOW);
    digitalWrite(xcoil1b, HIGH);
    digitalWrite(xcoil2a, LOW);
    digitalWrite(xcoil2b, LOW);

    delay(20);
  }

  // make sure the motor is ok, so it doesn't blow up
  digitalWrite(xcoil1a, LOW);
  digitalWrite(xcoil1b, LOW);
  digitalWrite(xcoil2a, LOW);
  digitalWrite(xcoil2b, LOW);

}

void xStepPatternBackward(int xNumberOfStepsb) { //towards breadboard
  for (int times = xNumberOfStepsb; times > 0; times--) {
    // step 8
    digitalWrite(xcoil1a, LOW);
    digitalWrite(xcoil1b, HIGH);
    digitalWrite(xcoil2a, LOW);
    digitalWrite(xcoil2b, LOW);

    delay(20);
    
    // step 7
    digitalWrite(xcoil1a, LOW);
    digitalWrite(xcoil1b, HIGH);
    digitalWrite(xcoil2a, HIGH);
    digitalWrite(xcoil2b, LOW);

    delay(20);

    // step 6
    digitalWrite(xcoil1a, LOW);
    digitalWrite(xcoil1b, LOW);
    digitalWrite(xcoil2a, HIGH);
    digitalWrite(xcoil2b, LOW);

    delay(20);
        
    // step 5
    digitalWrite(xcoil1a, HIGH);
    digitalWrite(xcoil1b, LOW);
    digitalWrite(xcoil2a, HIGH);
    digitalWrite(xcoil2b, LOW);

    delay(20);

    // step 4
    digitalWrite(xcoil1a, HIGH);
    digitalWrite(xcoil1b, LOW);
    digitalWrite(xcoil2a, LOW);
    digitalWrite(xcoil2b, LOW);

    delay(20);

    // step 3
    digitalWrite(xcoil1a, HIGH);
    digitalWrite(xcoil1b, LOW);
    digitalWrite(xcoil2a, LOW);
    digitalWrite(xcoil2b, HIGH);

    delay(20);

    // step 2
    digitalWrite(xcoil1a, LOW);
    digitalWrite(xcoil1b, LOW);
    digitalWrite(xcoil2a, LOW);
    digitalWrite(xcoil2b, HIGH);

    delay(20);

    // step 1
    digitalWrite(xcoil1a, LOW);
    digitalWrite(xcoil1b, HIGH);
    digitalWrite(xcoil2a, LOW);
    digitalWrite(xcoil2b, HIGH);

    delay(20);
  }

  // make sure the motor is ok, so it doesn't blow up
  digitalWrite(xcoil1a, LOW);
  digitalWrite(xcoil1b, LOW);
  digitalWrite(xcoil2a, LOW);
  digitalWrite(xcoil2b, LOW);
  
}

void yStepPatternForward(int yNumberOfStepsf) { //towards arduino

  for (int times = 0; times < yNumberOfStepsf; times++) {
    // step 1
    digitalWrite(ycoil1a, LOW);
    digitalWrite(ycoil1b, HIGH);
    digitalWrite(ycoil2a, LOW);
    digitalWrite(ycoil2b, HIGH);

    delay(20);
    
    // step 2
    digitalWrite(ycoil1a, LOW);
    digitalWrite(ycoil1b, LOW);
    digitalWrite(ycoil2a, LOW);
    digitalWrite(ycoil2b, HIGH);

    delay(20);
    
    // step 3
    digitalWrite(ycoil1a, HIGH);
    digitalWrite(ycoil1b, LOW);
    digitalWrite(ycoil2a, LOW);
    digitalWrite(ycoil2b, HIGH);

    delay(20);
    
    // step 4
    digitalWrite(ycoil1a, HIGH);
    digitalWrite(ycoil1b, LOW);
    digitalWrite(ycoil2a, LOW);
    digitalWrite(ycoil2b, LOW);

    delay(20);
    
    // step 5
    digitalWrite(ycoil1a, HIGH);
    digitalWrite(ycoil1b, LOW);
    digitalWrite(ycoil2a, HIGH);
    digitalWrite(ycoil2b, LOW);

    delay(20);
    
    // step 6
    digitalWrite(ycoil1a, LOW);
    digitalWrite(ycoil1b, LOW);
    digitalWrite(ycoil2a, HIGH);
    digitalWrite(ycoil2b, LOW);

    delay(20);
    
    // step 7
    digitalWrite(ycoil1a, LOW);
    digitalWrite(ycoil1b, HIGH);
    digitalWrite(ycoil2a, HIGH);
    digitalWrite(ycoil2b, LOW);

    delay(20);

    // step 8
    digitalWrite(ycoil1a, LOW);
    digitalWrite(ycoil1b, HIGH);
    digitalWrite(ycoil2a, LOW);
    digitalWrite(ycoil2b, LOW);

    delay(20);
  }

  // make sure the motor is ok, so it doesn't blow up
  digitalWrite(ycoil1a, LOW);
  digitalWrite(ycoil1b, LOW);
  digitalWrite(ycoil2a, LOW);
  digitalWrite(ycoil2b, LOW);

}

void yStepPatternBackward(int yNumberOfStepsb) { //away from arduino
  for (int times = yNumberOfStepsb; times > 0; times--) {
    // step 8
    digitalWrite(ycoil1a, LOW);
    digitalWrite(ycoil1b, HIGH);
    digitalWrite(ycoil2a, LOW);
    digitalWrite(ycoil2b, LOW);

    delay(20);
    
    // step 7
    digitalWrite(ycoil1a, LOW);
    digitalWrite(ycoil1b, HIGH);
    digitalWrite(ycoil2a, HIGH);
    digitalWrite(ycoil2b, LOW);

    delay(20);

    // step 6
    digitalWrite(ycoil1a, LOW);
    digitalWrite(ycoil1b, LOW);
    digitalWrite(ycoil2a, HIGH);
    digitalWrite(ycoil2b, LOW);

    delay(20);
        
    // step 5
    digitalWrite(ycoil1a, HIGH);
    digitalWrite(ycoil1b, LOW);
    digitalWrite(ycoil2a, HIGH);
    digitalWrite(ycoil2b, LOW);

    delay(20);

    // step 4
    digitalWrite(ycoil1a, HIGH);
    digitalWrite(ycoil1b, LOW);
    digitalWrite(ycoil2a, LOW);
    digitalWrite(ycoil2b, LOW);

    delay(20);

    // step 3
    digitalWrite(ycoil1a, HIGH);
    digitalWrite(ycoil1b, LOW);
    digitalWrite(ycoil2a, LOW);
    digitalWrite(ycoil2b, HIGH);

    delay(20);

    // step 2
    digitalWrite(ycoil1a, LOW);
    digitalWrite(ycoil1b, LOW);
    digitalWrite(ycoil2a, LOW);
    digitalWrite(ycoil2b, HIGH);

    delay(20);

    // step 1
    digitalWrite(ycoil1a, LOW);
    digitalWrite(ycoil1b, HIGH);
    digitalWrite(ycoil2a, LOW);
    digitalWrite(ycoil2b, HIGH);

    delay(20);
  }

  // make sure the motor is ok, so it doesn't blow up
  digitalWrite(ycoil1a, LOW);
  digitalWrite(ycoil1b, LOW);
  digitalWrite(ycoil2a, LOW);
  digitalWrite(ycoil2b, LOW);
  
}


/*
 * let's just. code all the letters
 * dimensions 10x5y
 * each letter starts in upper left, maybe let's make it end in the upper left of the next letter too
 * do we want to code pendown and penup within letters? sure.
 * so! assuming that letters start penup, above the upper left hand corner. 
 * also let's put 2 between each letter.
 * so like maybe with 40/7 that's like 5 letters per line
 */

void A() {
  penDown();
  xStepPatternBackward(10);
  xStepPatternForward(10);
  yStepPatternBackward(5);
  xStepPatternBackward(5);
  yStepPatternForward(5);
  yStepPatternBackward(5);
  xStepPatternBackward(5);
  xStepPatternForward(10);
  penUp();
  yStepPatternBackward(2);
}

void B() {
  penDown();
  xStepPatternBackward(10);
  yStepPatternBackward(5);
  xStepPatternForward(5);
  yStepPatternForward(5);
  yStepPatternBackward(5);
  xStepPatternForward(5);
  yStepPatternForward(5);
  yStepPatternBackward(5);
  penUp();
  yStepPatternBackward(2);
}

void C() {
  penDown();
  yStepPatternBackward(5);
  yStepPatternForward(5);
  xStepPatternBackward(10);
  yStepPatternBackward(5);
  penUp();
  xStepPatternForward(10);
  yStepPatternBackward(2);
}

void D() {
  penDown();
  yStepPatternBackward(5);
  xStepPatternBackward(10);
  yStepPatternForward(5);
  xStepPatternForward(10);
  yStepPatternBackward(5);
  penUp();
  yStepPatternBackward(2);
}

void E() {
  penDown();
  xStepPatternBackward(10);
  yStepPatternBackward(5);
  yStepPatternForward(5);
  xStepPatternForward(5);
  yStepPatternBackward(5);
  yStepPatternForward(5);
  xStepPatternForward(5);
  yStepPatternBackward(5);
  penUp();
  yStepPatternBackward(2);
}

void FF() { //called this because  F() is already a function
  penDown();
  xStepPatternBackward(10);
  xStepPatternForward(7);
  yStepPatternBackward(3);
  yStepPatternForward(3);
  xStepPatternForward(3);
  yStepPatternBackward(5);
  penUp();
  yStepPatternBackward(2);
}

void G() {
  penDown();
  yStepPatternBackward(5);
  yStepPatternForward(5);
  xStepPatternBackward(10);
  yStepPatternBackward(5);
  xStepPatternForward(5);
  yStepPatternForward(2);
  yStepPatternBackward(2);
  penUp();
  xStepPatternForward(5);
  yStepPatternBackward(2);
}

void H() {
  penDown();
  xStepPatternBackward(10);
  xStepPatternForward(5);
  yStepPatternBackward(5);
  xStepPatternBackward(5);
  xStepPatternForward(10);
  penUp();
  yStepPatternBackward(2);
}
  
void I() {
  penDown();
  xStepPatternBackward(10);
  xStepPatternForward(10);
  penUp();
  yStepPatternBackward(2);
}

void J() {
  xStepPatternBackward(9);
  penDown();
  xStepPatternBackward(1);
  yStepPatternBackward(5);
  xStepPatternForward(10);
  penUp();
  yStepPatternBackward(2);
}

void K() {
  penDown();
  xStepPatternBackward(10);
  xStepPatternForward(5);
  yStepPatternBackward(5);
  xStepPatternBackward(5);
  xStepPatternForward(10);
}

void L() {
  penDown();
  xStepPatternBackward(10);
  yStepPatternBackward(5);
  penUp();
  xStepPatternForward(10);
  yStepPatternBackward(2);
}

void M() {
  penDown();
  xStepPatternBackward(10);
  xStepPatternForward(10);
  yStepPatternBackward(2);
  xStepPatternBackward(5);
  xStepPatternForward(5);
  yStepPatternBackward(2);
  xStepPatternBackward(10);
  xStepPatternForward(10);
  penUp();
  yStepPatternBackward(2);
}

void N() {
  penDown();
  xStepPatternBackward(10);
  xStepPatternForward(10);
  yStepPatternBackward(5);
  xStepPatternBackward(10);
  xStepPatternForward(10);
  penUp();
  yStepPatternBackward(2);
}

void O() {
  penDown();
  yStepPatternBackward(5);
  xStepPatternBackward(10);
  yStepPatternForward(5);
  xStepPatternForward(10);
  yStepPatternBackward(5);
  penUp();
  yStepPatternBackward(2);
}

void Q() {
  int x;
  penDown();
  yStepPatternBackward(5);
  xStepPatternBackward(10);
  yStepPatternForward(5);
  xStepPatternForward(10);
  yStepPatternBackward(5);
  for (x=0; x<3; x++) {
    yStepPatternBackward(1);
    xStepPatternBackward(1); 
  }
  penUp();
  yStepPatternBackward(2);
  
}

void P() {
  penDown();
  xStepPatternBackward(10);
  xStepPatternForward(10);
  yStepPatternBackward(5);
  xStepPatternBackward(5);
  yStepPatternForward(5);
  yStepPatternBackward(5);
  xStepPatternForward(5);
  penUp();
  yStepPatternBackward(2);
}

void R() {
  penDown();
  xStepPatternBackward(10);
  xStepPatternForward(5);
  yStepPatternBackward(5);
  xStepPatternBackward(5);
  xStepPatternForward(10);
  yStepPatternForward(5);
  penUp();
  yStepPatternBackward(2);
}

void S() {
  penDown();
  yStepPatternBackward(5);
  yStepPatternForward(5);
  xStepPatternBackward(5);
  yStepPatternBackward(5);
  xStepPatternBackward(5);
  yStepPatternForward(5);
  penUp();
  xStepPatternForward(10);
  yStepPatternForward(8);
}

void T() {
  penDown();
  yStepPatternBackward(5);
  xStepPatternBackward(10);
  xStepPatternForward(10);
  yStepPatternBackward(5);
  penUp();
  yStepPatternBackward(2);
}

void U() {
  penDown();
  xStepPatternBackward(10);
  yStepPatternBackward(5);
  xStepPatternForward(10);
  penUp();
  yStepPatternBackward(2);
}

void V() {
  penDown();
  xStepPatternBackward(10);
  yStepPatternBackward(5);
  xStepPatternForward(10);
  penUp();
  yStepPatternBackward(2);
}

void W() {
  penDown();
  xStepPatternBackward(10);
  yStepPatternBackward(5);
  xStepPatternForward(5);
  xStepPatternBackward(5);
  yStepPatternBackward(5);
  xStepPatternForward(10);
  penUp();
  yStepPatternBackward(2);
}

void X() {
  penDown();
  xStepPatternBackward(10);
  xStepPatternForward(5);
  yStepPatternBackward(5);
  xStepPatternBackward(5);
  xStepPatternForward(10);
  penUp();
  yStepPatternBackward(2);
}

void Y() {
  penDown();
  xStepPatternBackward(3);
  yStepPatternBackward(2);
  xStepPatternBackward(7);
  xStepPatternForward(7);
  yStepPatternBackward(2);
  xStepPatternForward(3);
  penUp();
  yStepPatternBackward(2);
}

void Z() {
  penDown();
  yStepPatternBackward(5);
  xStepPatternBackward(5);
  yStepPatternForward(5);
  xStepPatternBackward(5);
  yStepPatternBackward(5);
  penUp();
  xStepPatternForward(10);
  yStepPatternBackward(2);
}

void space() {
  yStepPatternBackward(12);
}


void loop() {
  /*
   * x forward is pen towards glass
   * x backward is pen towards breadboard
   * y forward is pen toward arduino
   * y backward is pen away from arduino
   */
   
  /*if(Serial.available() >0) {
    A();
    B();
    Serial.write('0');
    while(true){
      delay(100);
    }
  }*/

 //put whatever letters you want to write here
  A();
  exit(0);
}

