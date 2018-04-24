/*
  EmSevenSegment Library - blink

 Demonstrates the use a 4094 shift register IC to control an array of Seven Segment Display.
 
 This sketch prints "123" and toggles the leading zeros On and Off.

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

}

//=============================================================//
void loop(){
  disp.set("zeros",'y');
  disp.print(123);
  delay(1000);
  disp.set("zeros",'n');
  disp.print(123);
  delay(1000);
}


