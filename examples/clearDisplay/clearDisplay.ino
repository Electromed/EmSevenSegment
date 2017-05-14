/*
  EmSevenSegment Library - blink

 Demonstrates the use a 4094 shift register IC to control an array of Seven Segment Display.
 
 This sketch prints "1234" and blinks the digits "23".

  The circuit:
 * 4094 Data pin to digital pin 10
 * 4094 Clock pin to digital pin 11
 * 4094 Strobe pin to digital pin 12

 Library originally released 17 May 2017
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
  disp.print(1234);
  delay(1000);
  disp.clear(2); //2nd digit to be blinked with a time period of 500ms
  delay(1000);
  disp.print(1234);
  delay(1000);
  disp.clear();
  delay(1000);
}

