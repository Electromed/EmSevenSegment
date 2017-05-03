#include <EmSevenSegment.h>

EmSevenSegment sev(4,'c',10,11,12);

void setup(){

}

//=============================================================//
void loop(){
  int arr[] = {5,12,3}; // Numbers to be displayed
  int len[] = {1, 2, 1}; // Number of 7-segment digits allocated to the number
  sev.writeNumbers(3,arr,len);
  delay(1000);
}


