/*
  EmSevenSegment Library - blink

 Demonstrates the use a 4094 shift register IC to control an array of Seven Segment Display.
 
 This sketch prints "1234" and blinks the digits "23".

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
  int arr[]={1,23,4}; //Numbers to be displayed
  int len[]={1,2,1}; // Number of 7-segment digitss allocated to the number
  disp.blink(3,arr,len,2,500); //2nd digit to be blinked with a time period of 500ms
}

