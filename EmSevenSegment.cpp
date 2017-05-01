
#include "Arduino.h"
#include "EmSevenSegment.h"

/*****************************************************************/

EmSevenSegment::EmSevenSegment(uint8_t digits,char type,uint8_t dataPin,uint8_t clockPin,uint8_t strobePin){
  // Default Constructor of EmSevenSegment class
  pinMode(dataPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(strobePin,OUTPUT);
  _digits=digits;
  _dataPin=dataPin;
  _clockPin=clockPin;
  _strobePin=strobePin;
  _leadingZeros=false;
  _print=false;
  _type=type;
}

void EmSevenSegment::setLeadingZeros(boolean leadingZeros){
  _leadingZeros=leadingZeros;
}

void EmSevenSegment::setSerialPrint(boolean p){
  _print=p;
}

/*****************************************************************/

uint8_t EmSevenSegment::findLength(unsigned long n){
  uint8_t l=0;
  while(n!=0){
    l++;
    n/=10;
  }
  return l;
}


void EmSevenSegment::serialPrint(String s){
  if (_print==true)
    Serial.println(s);
}

/*****************************************************************/

void EmSevenSegment::test(){
  int arr[_digits];
  for(int i=0;i<10;i++){
    for(int j=0;j<_digits;j++){
      arr[j]=i;
    }
    writeArray(arr);
    delay(100);
  }
}

/*****************************************************************/

void EmSevenSegment::writeNumbers(int nums,int num[],int len[]){
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

void EmSevenSegment::writeNumbers(int nums,int num[],int len[],int off){
  int arr[_digits];
  int t1=0,t2=-1,t3;
  for(int i=0;i<nums;i++){
    //Serial.println(num[i]);
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
        arr[_digits-1-(t2-j)]=t1%10;
        t1/=10;
        if(j>=t3 && _leadingZeros==false){
          arr[_digits-1-(t2-j)]=10;
        }
      }
    }
  }
  writeArray(arr);
}

void EmSevenSegment::blinkNumbers(int nums, int num[],int len[],int off,int blinkDelay){
  if ((millis() - _lastBlinkTime) > blinkDelay) {
    _lastBlinkTime=millis();
    if ((millis()/1000)%2 == 0){
      writeNumbers(nums,num,len,off);
    }
    else{
      writeNumbers(nums,num,len);
    }
  }
}

/*****************************************************************/

void EmSevenSegment::writeNum(unsigned long num){
  int arr[_digits];
  uint8_t len=0;
  //Serial.println(num);
  int x=num;
  len=findLength(num);
  if (len <= _digits){
    x=num;
  }
  else{
    serialPrint("num larger than digits");
    for (int j=0;j<len-_digits;j++){
      x/=10;
    }
  }
  for (int i=0;i<_digits;i++){
    if (i>=len){
      arr[i]=10;
    }
    else{
      if (_leadingZeros==false){
        arr[i]=x%10;
        x/=10;
      }
    }
  }
  writeArray(arr);
}

void EmSevenSegment::writeNum(unsigned long num,uint8_t c){
  int arr[_digits];
  uint8_t len=0;
  //Serial.println(num);
  int x=num;
  len=findLength(num);
  if (len <= _digits){
    x=num;
  }
  else{
    serialPrint("num larger than digits");
    for (int j=0;j<len-_digits;j++){
      x/=10;
    }
  }
  for (int i=0;i<_digits;i++){
    if (i>=len){
      arr[i]=10;
    }
    else{
      if (_leadingZeros==false){
        arr[i]=x%10;
        x/=10;
      }
    }
  }
  arr[c]=10;
  writeArray(arr);
}

void EmSevenSegment::blinkNum(unsigned long num,int off,int blinkDelay){
  if ((millis() - _lastBlinkTime) > blinkDelay) {
    _lastBlinkTime=millis();
    if ((millis()/1000)%2 == 0){
      writeNum(num);
    }
    else{
      writeNum(num,off-1);
    }
  }
}

/*****************************************************************/

void EmSevenSegment::writeArray(int arr[]){
  byte segment[]={63, 6, 91, 79, 102, 109, 125, 7, 127, 111,0};
  digitalWrite(_strobePin,LOW);
  for (int i=0;i<_digits;i++){
    byte digit=segment[arr[i]];
    if (_type == 'c'){
      writeHex(digit);
    }
    else {
      writeHex(~digit,0);
    }
  }
  digitalWrite(_strobePin,HIGH);
}

void EmSevenSegment::writeHex(byte x){
  digitalWrite(_strobePin,LOW);
  shiftOut(_dataPin,_clockPin,MSBFIRST,x);
  digitalWrite(_strobePin,HIGH);
}

void EmSevenSegment::writeHex(byte x,byte y){
  shiftOut(_dataPin,_clockPin,MSBFIRST,x);
}

/*****************************************************************/
