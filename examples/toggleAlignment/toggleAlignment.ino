/*
  EmSevenSegment Library - blink

 Demonstrates the use a 4094 shift register IC to control an array of Seven Segment Display.
 
 This sketch has a code that toggles the 
 alignment of digits 12 from left to right hand side.

  The circuit:
 * 4094 Data pin to digital pin 4
 * 4094 Clock pin to digital pin 3
 * 4094 Strobe pin to digital pin 2

 Library originally released 21 May 2017
 by Suhrid Srivastava

 This example code is in the public domain. 

 
*/

// include the library code:

#include <EmSevenSegment.h>

EmSevenSegment disp(4,'C',4,3,2);

void setup(){
  Serial.begin(9600);
  Serial.println("start");
}
  
//=============================================================//
void loop(){
  disp.set("align",'l');
  disp.print(12);
  delay(1000);
  disp.set("align",'r');
  disp.print(12);
  delay(1000);
}

