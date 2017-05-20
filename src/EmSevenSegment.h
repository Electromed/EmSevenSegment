
#ifndef EmSevenSegment_h
#define EmSevenSegment_h

#include "Arduino.h"

class EmSevenSegment{

  public :
    EmSevenSegment(char type,uint8_t dataPin,uint8_t clockPin,uint8_t strobePin);
    EmSevenSegment(int digits,char type,uint8_t dataPin,uint8_t clockPin,uint8_t strobePin);
    void set(String s,char x);
    void print();
    void print(char c);
    void print(long num);
    void print(long num,int digits);
    void print(int num);
    void print(int num,int digits);
    void print(String s);
    void print(String s,int digits);
    void blink(int nums, int num[],int len[],int off,int blinkDelay);
    void blink(int nums, String num[],int len[],int off,int blinkDelay);
    void clear();
    void clear(int digits);

  private:
    unsigned long _lastBlinkTime;
    uint8_t findLength(long n);
    void alignLeft(int arr[],int digits);
    void printHex(byte x,byte y);
    void writeDigits(int arr[],int digits);
    void writeDigits(int arr[]);
    void writeChar(int arr[]);
    void writeNum(long num,uint8_t c);
    void print(int nums,int num[],int len[]);
    void print(int nums,String num[],int len[]);
    void printArray(int nums,int num[],int len[],int off);
    void printArray(int nums,String num[],int len[],int off);
    void blinkNum(long num,int off,int blinkDelay);
    void printHex(byte x);
    
    uint8_t _digits;
    uint8_t _dataPin;
    uint8_t _clockPin;
    uint8_t _strobePin;
    char _type;
    char _align;
    boolean _leadingZeros;
    boolean _print;
};

#endif