# EmSevenSegment

This is a library to control 7-segment display using 4094 8-bit shift register.

## Features
  - Concatenate upto 255 displays using just 3 pins on Arduino
  - Prints both numbers and alphabets
  - Supports both common anode and common cathode displays
  - Directly print multiple integer values
  - Print arrays of numbers/strings
  - Add/remove leading zeros for numbers
  - Choose between left/right alignment of text
  - Blink at specific location on display

## Hardware required

The following are a must:
  - Any arduino board
  - Shift register 4094
  - 7-segment led display.

## Install

1. Download the library from github
2. Extract and copy the folder into Documents > Arduino > Libraries
3. Test using an example code from File > Examples > emSevenSegment > test

## Basic circuit

![input](https://raw.githubusercontent.com/ssuhrid/arduino-seven-segment-using-4094-Library/master/extras/1234.png)

Hardware requirements may change due to larger current requirement of bigger sized displays.

## Reference

### Constructor

* __Shift Display()__
  * EmSevenSegment disp(int digits,char type,uint8_t dataPin,uint8_t clockPin,uint8_t strobePin)
    
  Creates EmSevenSegment object, initializes the library with the interface pins, and sets up with the display properties.

  `disp`: is a variable of type EmSevenSegment.

  `digits`: is the number of single 7-segment displays connected in series.

  `dataPin`, `clockPin`, `strobePin`: are the number of the Arduino digital pins connected to the shift registers data, clock and strobe pins;
  
### Functions

* __print()__
  * disp.print(value)
  * disp.print(value, digits)

  `disp`: is a variable of type EmSevenSegment.

  `value`: is the value to save and show;
  can be a number (int, long) or text (char, String object);
  for text, valid characters are 0-9 a-z A-Z - space.

  `digits`: is the number of digits alloted to print the value;
  default value is the total Bi;
  for text, valid characters are 0-9 a-z A-Z - space.

* __printHex()__
  * disp.print(value)

  `disp`: is a variable of type EmSevenSegment.

  `value`: is the hex value to save and show;
  must be in the form of 0xXX;

* __printArray()__
  * disp.printArray(lengthOfArray,array,digitsForElement)

  `disp`: is a variable of type EmSevenSegment.

  'lengthOfArray': number of elements in array to be printed

  'array': array of elements to be printed

  'digitsForElement': number of digits alloted for each element

  Example of the blinking effect is as follows:

  ![input](https://raw.githubusercontent.com/ssuhrid/arduino-seven-segment-using-4094-Library/master/extras/blinkDisplay.jpg)

* __blinkArray()__
  * disp.blinkArray(lengthOfArray,array,digitsForElement,blinkingElement,blinkTime)

  `disp`: is a variable of type EmSevenSegment.

  'lengthOfArray': number of elements in array to be printed

  'array': array of elements to be printed

  'digitsForElement': number of digits alloted for each element

  `blinkingElement`: index of element to be blinked.

  'blinkTime': blinking time of the element

* __test()__
  * disp.test()

  `disp`: is a variable of type EmSevenSegment.

* __setAlignment()__
  * disp.print(value)

  `disp`: is a variable of type EmSevenSegment.

  `value`: L for left align;
  R for right align;

  
* __setLeadingZeros()__
  * disp.print(value)
  
  `disp`: is a variable of type EmSevenSegment.

  `value`: true to print leading zeros;
  false to not print leading zeros;
  
## TODO

  Will update this section once issues are discovered.

## Contacts

suhrid.srivastava@gmail.com

