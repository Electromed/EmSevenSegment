#include <sevSeg4094.h>

sevSeg4094 sev(4,10,11,12);

void setup(){
  Serial.begin(9600);
  Serial.print("Start");
  pinMode(strobe,OUTPUT);
  pinMode(data,OUTPUT);
  pinMode(clk,OUTPUT);
  buttonInit();
  setInterruptButton(2);
}

//=============================================================//
void loop(){
  //checkUP();
  //test();
  if (mode == 'n')
    writeNumbers(nums,numbers,lengths);
  else if (mode == 's'){
    byte thisSwitch=thisSwitch_justPressed();
    if (thisSwitch!=255)
      Serial.println(thisSwitch);
    createBlink(nums,numbers,lengths,2,500);
    
    //delay(1000);
  }
}


