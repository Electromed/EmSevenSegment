#include <sevSeg4094.h>

sevSeg4094 sev(4,10,11,12);

void setup(){
  Serial.begin(9600);
}

//=============================================================//
void loop(){
  sev.test();

}


