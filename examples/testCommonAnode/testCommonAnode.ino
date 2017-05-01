#include <EmSevenSegment.h>

EmSevenSegment sev(4,'a',10,11,12);

void setup(){
  Serial.begin(9600);
}

//=============================================================//
void loop(){
  sev.test();
}


