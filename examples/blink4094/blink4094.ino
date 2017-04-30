#include <sevSeg4094.h>

sevSeg4094 sev(4,10,11,12);

void setup(){
  Serial.begin(9600);
}

//=============================================================//
void loop(){
  int arr[]={5,67,3};
  int len[]={1,2,1};
  sev.createBlink(3,arr,len,2,500);
}


