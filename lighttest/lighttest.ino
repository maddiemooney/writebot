
int usbnumber = 0; //this variable holds what we are currently reading from serial


void setup() { //call this once at the beginning
  Serial.begin(9600); //start up serial port
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() { //main loop

  //Serial.print(usbnumber);
  /*digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);*/

  if (Serial.available() > 0) { //if there is anything on the serial port, read it
    usbnumber = Serial.read(); //store it in the usbnumber variable
    digitalWrite(LED_BUILTIN, HIGH);
    delay(3000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(3000);
  }

  if (usbnumber > 0) { //if we read something

    digitalWrite(LED_BUILTIN, HIGH);
    delay(3000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(3000);
    
    if (usbnumber == 49) { //49
      Serial.print("stop??");
      digitalWrite(LED_BUILTIN, HIGH);
      delay(2000);                      
      digitalWrite(LED_BUILTIN, LOW);
      delay(2000);
    }
    if (usbnumber == 50) {
      Serial.print("slowwww");
      while (true) {
      digitalWrite(LED_BUILTIN, HIGH);   
      delay(2000);                      
      digitalWrite(LED_BUILTIN, LOW);   
      delay(2000);
      }
    }
    if (usbnumber == 51) {
      Serial.print("medium");
      digitalWrite(LED_BUILTIN, HIGH);  
      delay(2000);                       
      digitalWrite(LED_BUILTIN, LOW);    
      delay(2000);
    }
    if (usbnumber == 52) {
      Serial.print("sonic");
      digitalWrite(LED_BUILTIN, HIGH);   
      delay(2000);                       
      digitalWrite(LED_BUILTIN, LOW);    
      delay(2000);

    }
    
  }
  //usbnumber = 0; //reset
}
