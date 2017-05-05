
#ifndef EmSevenSegment_h
#define EmSevenSegment_h

#include "Arduino.h"

class EmSevenSegment{

  public :
    EmSevenSegment(uint8_t digits,char type,uint8_t dataPin,uint8_t clockPin,uint8_t strobePin);
    void setLeadingZeros(boolean leadingZeros);
    void writeNumbers(int nums,int num[],int len[]);
    void writeNumbers(int nums,int num[],int len[],int off);
    void blinkNumbers(int nums, int num[],int len[],int off,int blinkDelay);
    void print(unsigned long num);
    void print(String s);
    void writeNum(unsigned long num,uint8_t c);
    void blinkNum(unsigned long num,int off,int blinkDelay);
    void writeHex(byte x);
    void test();
  
  private:
    unsigned long _lastBlinkTime;
    uint8_t findLength(unsigned long n);
    void writeHex(byte x,byte y);
    void writeArray(int arr[]);
    void writeChar(int arr[]);
    
    uint8_t _digits;
    uint8_t _dataPin;
    uint8_t _clockPin;
    uint8_t _strobePin;
    char _type;
    boolean _leadingZeros;
    boolean _print;
};

#endif