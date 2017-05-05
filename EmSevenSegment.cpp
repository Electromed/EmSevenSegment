
#include "Arduino.h"
#include "EmSevenSegment.h"
#include "CharacterEncoding.h"

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
  Serial.begin(9600);
}

void EmSevenSegment::setLeadingZeros(boolean leadingZeros){
  _leadingZeros=leadingZeros;
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

/*****************************************************************/

void EmSevenSegment::test(){
  int arr[_digits];
  for(int i=0;i<10;i++){
    for(int j=0;j<_digits;j++){
      arr[j]=i;
    }
    writeDigits(arr);
    delay(100);
  }
}

/*****************************************************************/

void EmSevenSegment::writeArray(int nums,int num[],int len[]){
  int arr[_digits];
  int t1=0,t2=-1,t3;
  for(int i=0;i<nums;i++){
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
  writeDigits(arr);
}

void EmSevenSegment::writeArray(int nums,String num[],int len[]){
  int t1=0,t2=0,t3;
  String str = "";
  for(int i=0;i<nums;i++){
    String x=num[i];
    int length = x.length();
    if (length<len[i]){
      x="";
      for(int j=0;j<len[i]-length;j++){
        x+=" ";
      }
      for(int j=0;j<len[i];j++){
        x+=num[i].charAt(j);
      }
    }
          Serial.println(x);

    for(int j=0;j<len[i];j++){
        char c;
        c=x.charAt(j);
        str+=c;
    }
   // t2+=len[i];    
  }
  String temp = str;
  Serial.print("sex");
    Serial.println(str);
    print(str);
}

void EmSevenSegment::writeNumbers(int nums,int num[],int len[],int off){
  int arr[_digits];
  int t1=0,t2=-1,t3;
  for(int i=0;i<nums;i++){
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
  for(int i=0;i<_digits;i++)
    Serial.print(arr[i]);
  writeDigits(arr);
}

void EmSevenSegment::blinkNumbers(int nums, int num[],int len[],int off,int blinkDelay){
  if ((millis() - _lastBlinkTime) > blinkDelay) {
    _lastBlinkTime=millis();
    if ((millis()/1000)%2 == 0){
      writeNumbers(nums,num,len,off);
    }
    else{
      writeArray(nums,num,len);
    }
  }
}

/*****************************************************************/

void EmSevenSegment::print(unsigned long num){
  //To print an integer
  int arr[_digits];
  uint8_t len=0;
  int x=num;
  len=findLength(num);
  if (len <= _digits){
    x=num;
  }
  else{
    for (int j=0;j<len-_digits;j++){
      x/=10;
    }
  }
  for (int i=0;i<_digits;i++){
    if (i>=len){
      if (_leadingZeros == false){
        arr[i]=10;
      }
      else{
        arr[i]=0;
      }
    }
    else{
      arr[i]=x%10;
      x/=10;
    }
  }
  writeDigits(arr);
}

void EmSevenSegment::print(unsigned long num,int digits){
  //To print an integer
  int arr[digits];
  uint8_t len=0;
  int x=num;
  len=findLength(num);
  if (len <= digits){
    x=num;
  }
  else{
    for (int j=0;j<len-digits;j++){
      x/=10;
    }
  }
  for (int i=0;i<digits;i++){
    if (i>=len){
      if (_leadingZeros == false){
        arr[i]=10;
      }
      else{
        arr[i]=0;
      }
    }
    else{
      arr[i]=x%10;
      x/=10;
    }
  }
  writeDigits(arr,digits);
}

void EmSevenSegment::print(char c){
  Serial.println(c);
  if (c>='A' && c <='Z')
    c=c-'A';
  else if (c >='0' && c <= '9'){
    c=c-'0'+27;
  }
  else if (c >= 'a' && c <= 'z'){
    c=c-'a';
  }
  else if (c == 32){
    c=26;
  }
  byte digit;
  if (c<27){
    digit = LETTERS[c];
  }
  else if (c >=27 && c <= 36){
    digit = NUMBERS[c-27];
  }
  Serial.println(c);
  writeHex(digit);    
}

void EmSevenSegment::print(String s){
  //To print a String
  int arr[_digits];
  int temp[_digits];
  uint8_t len=0;
  len=s.length();
  if (len <= _digits){ 
  }
  else{
    // Take starting letters if space is less
    s=s.substring(0,_digits);
  }
  for (int i=0;i<_digits;i++){
    if (i>=len){
      arr[i]=26; // 26 = blank
    }
    else{
      char c=s.charAt(s.length()-1-i);
      if (c>='A' && c <='Z')
        c=c-'A';
      else if (c >='0' && c <= '9'){
        c=c-'0'+27;
      }
      else if (c >= 'a' && c <= 'z'){
        c=c-'a';
      }
      else if (c == 32){
        c=26;
      }
      arr[i]=c;
      Serial.print(arr[i]);
    }
  }
  writeChar(arr);
}

/*****************************************************************/

void EmSevenSegment::writeNum(unsigned long num,uint8_t c){
  int arr[_digits];
  uint8_t len=0;
  int x=num;
  len=findLength(num);
  if (len <= _digits){
    x=num;
  }
  else{
    for (int j=0;j<len-_digits;j++){
      x/=10;
    }
  }
  for (int i=0;i<_digits;i++){
    if (i>=len){
      if (_leadingZeros == false){
        arr[i]=10;
      }
      else{
        arr[i]=0;
      }
    }
    else{
      arr[i]=x%10;
      x/=10;
    }
  }
  arr[c]=10;
  writeDigits(arr);
}

void EmSevenSegment::blinkNum(unsigned long num,int off,int blinkDelay){
  if ((millis() - _lastBlinkTime) > blinkDelay) {
    _lastBlinkTime=millis();
    if ((millis()/1000)%2 == 0){
      print(num);
    }
    else{
      writeNum(num,off-1);
    }
  }
}

/*****************************************************************/

void EmSevenSegment::writeDigits(int arr[]){
  //For right align, called via internal functions
  digitalWrite(_strobePin,LOW);
  for (int i=0;i<_digits ;i++){
    //byte digit=segment[arr[i]];
    byte digit = NUMBERS[arr[i]];
    if (_type == 'c'){
      writeHex(digit,0);
    }
    else {
      writeHex(~digit,0);
    }
  }
  digitalWrite(_strobePin,HIGH);
}

void EmSevenSegment::writeDigits(int arr[],int digits){
  //For right align, called via internal functions
  digitalWrite(_strobePin,LOW);
  for (int i=0;i<digits;i++){
    //byte digit=segment[arr[i]];
    byte digit = NUMBERS[arr[i]];
    if (_type == 'c'){
      writeHex(digit,0);
    }
    else {
      writeHex(~digit,0);
    }
  }
  digitalWrite(_strobePin,HIGH);
}

void EmSevenSegment::writeChar(int arr[]){
  //For right align, called via internal functions
  digitalWrite(_strobePin,LOW);
  for (int i=0;i<_digits ;i++){
    //byte digit=segment[arr[i]];
    byte digit = LETTERS[arr[i]];
    if (arr[i] >=27 && arr[i] <=36)
      digit=NUMBERS[arr[i]-27];
    if (_type == 'c'){
      writeHex(digit,0);
    }
    else {
      writeHex(~digit,0);
    }
//    Serial.println(digit);
  }
//  Serial.println("sex");
  digitalWrite(_strobePin,HIGH);
}

/*void EmSevenSegment::writeArray(int arr[],boolean x){
  //For left align
  digitalWrite(_strobePin,LOW);
  int len = sizeof(arr)/sizeof(arr[0]);
  for (int i=0;i<_digits;i++){
    byte digit=NUMBERS[arr[_digits-1-i]];
    if (_type == 'c'){
      writeHex(digit,0);
    }
    else {
      writeHex(~digit,0);
    }
  }
  digitalWrite(_strobePin,HIGH);
}*/

void EmSevenSegment::writeHex(byte x){
  digitalWrite(_strobePin,LOW);
  shiftOut(_dataPin,_clockPin,LSBFIRST,x);
  digitalWrite(_strobePin,HIGH);
}

void EmSevenSegment::writeHex(byte x,byte y){
  shiftOut(_dataPin,_clockPin,LSBFIRST,x);
}

/*****************************************************************/
