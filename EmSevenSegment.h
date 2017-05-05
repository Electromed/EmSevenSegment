
#ifndef EmSevenSegment_h
#define EmSevenSegment_h

#include "Arduino.h"

class EmSevenSegment{

  public :
    EmSevenSegment(uint8_t digits,char type,uint8_t dataPin,uint8_t clockPin,uint8_t strobePin);
    void setLeadingZeros(boolean leadingZeros);
    void printArray(int nums,int num[],int len[]);
    void printArray(int nums,String num[],int len[]);
    void blinkArray(int nums, int num[],int len[],int off,int blinkDelay);
    void blinkArray(int nums, String num[],int len[],int off,int blinkDelay);
    void print(char c);
    void print(long num);
    void print(long num,int digits);
    void print(int num);
    void print(int num,int digits);
    void print(String s);
    void print(String s,int digits);
    void blinkNum(long num,int off,int blinkDelay);
    void printHex(byte x);
    void test();
  
  private:
    unsigned long _lastBlinkTime;
    uint8_t findLength(long n);
    void printHex(byte x,byte y);
    void writeDigits(int arr[]);
    void writeDigits(int arr[],int digits);
    void writeChar(int arr[]);
    void writeNum(long num,uint8_t c);
    void printArray(int nums,int num[],int len[],int off);
    void printArray(int nums,String num[],int len[],int off);
    
    uint8_t _digits;
    uint8_t _dataPin;
    uint8_t _clockPin;
    uint8_t _strobePin;
    char _type;
    boolean _leadingZeros;
    boolean _print;
};

#endif