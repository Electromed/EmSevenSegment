/*
  EmSevenSegment Library - blink

 Demonstrates the use a 4094 shift register IC to control an array of Seven Segment Display.
 
 This sketch prints "6789" and "test" on the display infintely.

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
  int number = 6789; //Number to be displayed
  disp.print(number); // Print the number
  int str = "test" ; //String to be displayed
  disp.print(str); // Print the number
}

