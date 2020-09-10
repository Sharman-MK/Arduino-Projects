/*
 * Modified by MC, D'Maker Store
 * based on IRremote Library - Ken Shirriff
*/
 
#include <IRremote.h>
 
int IR_Recv = A2;   //IR Receiver Pin 3
int S1Pin = 7;
int S2Pin = 6;
int S3Pin = 5;
 
IRrecv irrecv(IR_Recv);
decode_results results;
 
void setup(){
  Serial.begin(9600);  //starts serial communication
  irrecv.enableIRIn(); // Starts the receiver
  pinMode(S1Pin, OUTPUT);      // sets the digital pin as output
  pinMode(S2Pin, OUTPUT);      // sets the digital pin as output
  pinMode(S3Pin, OUTPUT);      // sets the digital pin as output 
  pinMode(A4, OUTPUT);
  pinMode(A3, OUTPUT);  
  digitalWrite(S1Pin, HIGH);
  digitalWrite(S2Pin, HIGH);
  digitalWrite(S3Pin, HIGH);
}
 
void loop(){
  digitalWrite(A4, HIGH);
  digitalWrite(A3, LOW);
 
  //decodes the infrared input
  if (irrecv.decode(&results)){
    long int decCode = results.value;
    Serial.println(results.value);
    
    //switch case to use the selected remote control button
    switch (results.value){
      case 4294967295: //when you press the page up button
        digitalWrite(S1Pin, LOW);
        Serial.println("S1 On");
        break;   
        
      case  835848: //when you press the page down button
        digitalWrite(S1Pin, HIGH);
        Serial.println("S1 Off");   
        break;
        
       case 4294967295: //when you press the ezoom + button
        digitalWrite(S2Pin, LOW);
        Serial.println("S2 On");
        break;           
        
       case 8203: //when you press the ezoom - button
        digitalWrite(S2Pin, HIGH);
        Serial.println("S2 Off");
        break;       
        
       case 2519691162: //when you press the 3 button
        digitalWrite(S3Pin, LOW);
        Serial.println("S3 On");
        break;       
        
       case  180488: //when you press the 6 button
        digitalWrite(S3Pin, HIGH);
        Serial.println("S3 Off");
        break;
        
       case 21514: //when you press the ENTER button
        digitalWrite(S1Pin, HIGH);
        digitalWrite(S2Pin, HIGH);
        digitalWrite(S3Pin, HIGH);
        Serial.println("All Off");
        break;
        
        case  2704: //when you press the ENTER button
        digitalWrite(S1Pin, LOW);
        digitalWrite(S2Pin, LOW);
        digitalWrite(S3Pin, LOW);
        Serial.println("All On");
        break;
    }
    irrecv.resume(); // Receives the next value from the button you press
  }
  delay(500);
}
