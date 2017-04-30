
#include "Arduino.h"
#include "sevSeg4094.h"

sevSeg4094::sevSeg4094(uint8_t digits,uint8_t dataPin,uint8_t clockPin,uint8_t strobePin){
  pinMode(dataPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(strobePin,OUTPUT);
  _digits=digits;
  _dataPin=dataPin;
  _clockPin=clockPin;
  _strobePin=strobePin;
  _leadingZeros=false;
}

uint8_t sevSeg4094::findLength(unsigned long n){
  uint8_t l=0;
  while(n!=0){
    l++;
    n/=10;
  }
  return l;
}

void setLeadingZeros(boolean leadingZeros){
  _leadingZeros=leadingZeros;
}


void sevSeg4094::writeArray(int arr[]){
  byte segment[]={63, 6, 91, 79, 102, 109, 125, 7, 127, 111,0};
  digitalWrite(_strobePin,LOW);
  for (int i=0;i<_digits;i++){
    byte digit=segment[arr[i]];
    shiftOut(_dataPin,_clockPin,MSBFIRST,digit);
  }
  digitalWrite(_strobePin,HIGH);
}

void sevSeg4094::test(){
  int arr[_digits];
  for(int i=0;i<10;i++){
    for(int j=0;j<_digits;j++){
      arr[j]=i;
    }
    writeArray(arr);
    delay(100);
  }
}
void sevSeg4094::writeNumbers(int nums,int num[],int len[]){
  int arr[_digits];
  int t1=0,t2=-1,t3;
  for(int i=0;i<nums;i++){
    Serial.println(num[i]);
    t1=num[i];
    t2+=len[i];
    t3=findLength(t1);
    for (int j=0;j<t3-len[i];j++){
      t1/=10;
    }
    for(int j=0;j<len[i];j++){
      arr[_digits-1-(t2-j)]=t1%10;
      t1/=10;
      if(j>=t3 && _leadingZeros==false){
        arr[_digits-1-(t2-j)]=10;
      }
    }    
  }
  writeArray(arr);
}
void sevSeg4094::writeNumbers(int nums,int num[],int len[],int off){
  int arr[_digits];
  int t1=0,t2=-1,t3;
  for(int i=0;i<nums;i++){
    Serial.println(num[i]);
    t1=num[i];
    t2+=len[i];
    t3=findLength(t1);
    if (i == off-1){
      for(int j=0;j<len[i];j++){
        arr[_digits-1-(t2-j)]=10;
      }      
    }
    else{
      for (int j=0;j<t3-len[i];j++){
        t1/=10;
      }
      for(int j=0;j<len[i];j++){
        arr[digits-1-(t2-j)]=t1%10;
        t1/=10;
        if(j>=t3 && _leadingZeros==false){
          arr[_digits-1-(t2-j)]=10;
        }
      }
    }
  }
  writeArray(arr);
}
void sevSeg4094::createBlink(int nums, int num[],int len[],int off,int blinkDelay){
  if ((millis() - lastBlinkTime) > blinkDelay) {
    lastBlinkTime=millis();
    if ((millis()/1000)%2 == 0){
      writeNumbers(nums,num,len,off);
    }
    else{
      writeNumbers(nums,num,len);
    }
  }
}
