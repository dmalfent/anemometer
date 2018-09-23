#include <Arduino.h>
#include "lcdDisplay.h"
#include "handleInterrupt.h"
#include "digitalInput.h"

/**********************************************************/
#define SAMPLERATE 500000 //Hz
#define ENCODER_INC 3600
#define RADIUS_ROTOR 0.04 //m
/*********************************************************/
double nSpeed = 0.0;
double nSampleTime = 1 / SAMPLERATE;
double nEncoderRes = 360 / (ENCODER_INC*4) * DEG_TO_RAD; //rad
int nTimeInc = 0;
lcdDisplay lcdDisp;
handleInterrupt interrupt;
digitalInput DIN2(2);
digitalInput DIN3(3);
/*********************************************************/
void setup()
{

  lcdDisp.initDisplay();
  interrupt.init500kHzInterrupt();
  DIN2.init();
  DIN3.init();
}
/*********************************************************/
void loop()
{

  lcdDisp.updateSpeed(nSpeed);

}
/************************************************************/
ISR(TIMER1_COMPA_vect)//timer1 interrupt 2Hz
{
  DIN2.detectEdge();
  DIN3.detectEdge();

  if( DIN2.bChangedEdge || DIN3.bChangedEdge)
  {
    nSpeed = nEncoderRes / (nTimeInc * nSampleTime) * RADIUS_ROTOR; // v = w*r [m/s]
    nTimeInc = 0;
  }
  nTimeInc++;
}


