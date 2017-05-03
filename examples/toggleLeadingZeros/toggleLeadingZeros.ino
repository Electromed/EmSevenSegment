#include <EmSevenSegment.h>

EmSevenSegment sev(4,'c',10,11,12);

void setup(){

}

//=============================================================//
void loop(){
  sev.setLeadingZeros(true);
  sev.writeNum(123);
  delay(1000);
  sev.setLeadingZeros(false);
  sev.writeNum(123);
  delay(1000);
}


