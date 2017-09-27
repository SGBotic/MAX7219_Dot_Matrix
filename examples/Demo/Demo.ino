/*
Demo of MAX7219_Dot_Matrix library
Static display of character(s)


PINOUT:
MODULE.....UNO/NANO.....MEGA
VCC........+5V..........+5V
GND........GND..........GND
DIN........11...........51
CS (LOAD)..10...........10
CLK........13...........52
    
*/


#include <SPI.h>
#include <MAX7219_Dot_Matrix.h>

/* Set the CS digital pin number*/
#define CS 10

/* Set the number of 8*8 module */
#define modules 4     // 4 units of 8*8 module is connected to serial bus
//#define modules 1   // only one moudle is connected to serial bus

MAX7219_Dot_Matrix myDisplay (modules, CS);  // Initialise with no. of module and CS pin

void setup ()
  {  
  myDisplay.begin ();
  myDisplay.setIntensity (15);
  myDisplay.sendString ("1234");
  }  // end of setup

void loop ()
  {
  // do whatever here
  }  // end of loop
  
