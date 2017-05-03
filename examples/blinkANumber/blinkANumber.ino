#include <EmSevenSegment.h>

EmSevenSegment sev(4,'c',10,11,12);

void setup(){
  Serial.begin(9600);
}

//=============================================================//
void loop(){
  int arr[]={5,67,3}; //Numbers to be displayed
  int len[]={1,2,1}; // Number of 7-segment digitss allocated to the number
  sev.blinkNumbers(3,arr,len,2,500); //2nd digit to be blinked with a time period of 500ms
}

