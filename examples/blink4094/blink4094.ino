#include <EmSevenSegment.h>

EmSevenSegment sev(4,'c',10,11,12);

void setup(){
  Serial.begin(9600);
}

//=============================================================//
void loop(){
  int arr[]={5,67,3};
  int len[]={1,2,1};
  sev.blinkNumbers(3,arr,len,2,500);
}

