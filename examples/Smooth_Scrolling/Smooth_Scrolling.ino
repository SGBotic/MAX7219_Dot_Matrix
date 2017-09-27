/*
Demo of MAX7219_Dot_Matrix library
Sideways scrolling of one pixel at a time


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

const char message [] = "Testing 1234567890";
 
void setup ()
  {
  myDisplay.begin ();
  }  // end of setup

unsigned long lastMoved = 0;
unsigned long MOVE_INTERVAL = 20;  // mS
int  messageOffset;

void updateDisplay ()
  {
  myDisplay.sendSmooth (message, messageOffset);
  
  // next time show one pixel onwards
  if (messageOffset++ >= (int) (strlen (message) * 8))
    messageOffset = - modules * 8;
  }  // end of updateDisplay

void loop () 
  { 
    
  // update display if time is up
  if (millis () - lastMoved >= MOVE_INTERVAL)
    {
    updateDisplay ();
    lastMoved = millis ();
    }

  // do other stuff here    
     
  }  // end of loop

