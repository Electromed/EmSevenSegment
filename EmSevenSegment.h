
#ifndef EmSevenSegment_h
#define EmSevenSegment_h

#include "Arduino.h"

class EmSevenSegment{

  public :
    EmSevenSegment(uint8_t digits,char type,uint8_t dataPin,uint8_t clockPin,uint8_t strobePin);
    void setLeadingZeros(boolean leadingZeros);
    void writeArray(int nums,int num[],int len[]);
    void writeArray(int nums,String num[],int len[]);
    void blinkNumbers(int nums, int num[],int len[],int off,int blinkDelay);
    void print(char c);
    void print(unsigned long num);
    void print(unsigned long num,int digits);
    void print(String s);
    void print(String s,int digits);
    void blinkNum(unsigned long num,int off,int blinkDelay);
    void writeHex(byte x);
    void test();
  
  private:
    unsigned long _lastBlinkTime;
    uint8_t findLength(unsigned long n);
    void writeHex(byte x,byte y);
    void writeDigits(int arr[]);
    void writeDigits(int arr[],int digits);
    void writeChar(int arr[]);
    void writeNum(unsigned long num,uint8_t c);
    void writeNumbers(int nums,int num[],int len[],int off);
    
    uint8_t _digits;
    uint8_t _dataPin;
    uint8_t _clockPin;
    uint8_t _strobePin;
    char _type;
    boolean _leadingZeros;
    boolean _print;
};

#endif