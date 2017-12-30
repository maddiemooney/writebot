# writebot

Project for Arduino that takes in letters to write and makes a serial motor move in the x and y direction (and pen up and down in z direction). 

Stepper motor works in half steps, the Arduino library for stepper motors for some reason didn't work so I rewrote it here. 

Some attempts were made to communicate with serial ports to make user interface not janky. These attempts did not come to fruition, but the PHP and Python code is here nonetheless.
