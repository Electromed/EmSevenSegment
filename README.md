# EmSevenSegment

This is a library to control 7-segment display using 4094 8-bit shift register.
It has been tested on HEF4094B, CD4094B,  CD4094BMS, & MC74HCT4094A 

## Features
  - Concatenate upto 255 displays using just 3 pins of Arduino
  - Prints both numbers and alphabets
  - Supports both common anode and common cathode displays
  - Directly print multiple integer values
  - Print arrays of numbers/strings
  - Add/remove leading zeros for numbers
  - Choose between left/right alignment of text
  - Blink at specific location on display
  - Clear the display

## Install

1. Download the library from github
2. Extract and copy the folder into Documents > Arduino > Libraries
3. Test using an example code from File > Examples > EmSevenSegment > test

## Hardware required

The following are a must:
  - Any arduino board
  - Shift register 4094
  - 7-segment led display.

## Basic circuit

![input](https://raw.githubusercontent.com/ssuhrid/arduino-seven-segment-using-4094-Library/master/extras/1234.png)

Hardware requirements may change due to larger current requirement of bigger sized displays.

## Reference

### Constructor

* __EmSevenSegment()__
  * EmSevenSegment disp(char type,uint8_t dataPin,uint8_t clockPin,uint8_t strobePin)
  * EmSevenSegment disp(int digits,char type,uint8_t dataPin,uint8_t clockPin,uint8_t strobePin)
    
  Creates EmSevenSegment object, initializes the library with the interface pins, and sets up with the display properties.

  `disp`: is a variable of type EmSevenSegment.

  `type`: C for common cathode;
  A for common anode;

  `digits`: is the number of single 7-segment displays connected in series. default value is 1.

  `dataPin`, `clockPin`, `strobePin`: are the number of the Arduino digital pins connected to the shift registers data, clock and strobe pins.
  
### Functions

* __print()__
  * disp.print(value)
  * disp.print(value, digits)
  * disp.print(lengthOfArray,array,digitsForElement)

  To print a value on the 7-segment display

  `disp`: is a variable of type EmSevenSegment.

  `value`: is the value to save and show;
  can be a number (int, long) or text (char, String object);
  for text, valid characters are 0-9 a-z A-Z - space.

  `digits`: is the number of digits alloted to print the value;
  default value is the total number displays connected.

  `lengthOfArray`: number of elements in array to be printed.

  `array`: array of elements to be printed.

  `digitsForElement`: number of digits alloted for each element.

* __clear()__
  * disp.clear()
  * disp.clear(digits)

  To clear the display.

  `disp`: is a variable of type EmSevenSegment.

  `digits`: is the number of digits to be cleared;
  default value is the total number of displays connected.

* __blink()__
  * disp.blink(lengthOfArray,array,digitsForElement,blinkingElement,blinkTime)

  To blink at a particular location in the display.

  `disp`: is a variable of type EmSevenSegment.

  `lengthOfArray`: number of elements in array to be printed.

  `array`: array of elements to be printed.

  `digitsForElement`: number of digits alloted for each element.

  `blinkingElement`: index of element to be blinked.

  `blinkTime`: blinking time of the element.

* __set()__
  * disp.set(param,value)

  To set the parameters of the display.

  `disp`: is a variable of type EmSevenSegment.

  `param`: "ALIGN" to set alignment; "ZEROS" to show/hide leading zeros.
  
  `value`: for alignment: L for left align; R for right align; default set to right;
  for leading zeros: Y to show leading zeros; N to hide leading zeros; default set to N;
    
## TODO

  Will update this section once issues are discovered.

## Contacts

suhrid.srivastava@gmail.com