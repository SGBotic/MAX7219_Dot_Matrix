/*
  Demo of MAX7219_Dot_Matrix library
  to display a beating heart


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
#define modules 1   // only one moudle is connected to serial bus

MAX7219_Dot_Matrix myDisplay (modules, CS);  // Initialise with no. of module and CS pin

const unsigned char heart[] =
{
  B01100110,
  B11111111,
  B11111111,
  B11111111,
  B01111110,
  B00111100,
  B00011000,
  B00000000
};




void setup ()
{
  myDisplay.begin ();
  myDisplay.setIntensity (0);

  myDisplay.sendToAll(1, heart[0]);
  myDisplay.sendToAll(2, heart[1]);
  myDisplay.sendToAll(3, heart[2]);
  myDisplay.sendToAll(4, heart[3]);
  myDisplay.sendToAll(5, heart[4]);
  myDisplay.sendToAll(6, heart[5]);
  myDisplay.sendToAll(7, heart[6]);
  myDisplay.sendToAll(8, heart[7]);
}



void loop ()
{
  for (int INTENSITY = 0; INTENSITY < 10; INTENSITY++)
  {
    myDisplay.setIntensity (INTENSITY);
    delay(100);
  }
  for (int INTENSITY = 9; INTENSITY > 0; INTENSITY--)
  {
     myDisplay.setIntensity (INTENSITY);
    delay(100);
  }
  

}
