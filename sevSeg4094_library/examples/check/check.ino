#include <sevSeg4094.h>

sevSeg4094 sev(4,10,11,12);

void setup(){
  Serial.begin(9600);
}

//=============================================================//
void loop(){
  //sev.test();
  int arr[]={34,2,5};
  int len[]={2,1,1};
  sev.createBlink(3,arr,len,2,500);
}


