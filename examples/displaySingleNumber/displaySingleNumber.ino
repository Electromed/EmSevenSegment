#include <EmSevenSegment.h>

EmSevenSegment sev(4,'c',10,11,12);

void setup(){

}

//=============================================================//
void loop(){
  int number = 1234;
  sev.writeNum(number);
  delay(1000);
}

