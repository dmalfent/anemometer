#include <Arduino.h>
#include "lcdDisplay.h"
#include "handleInterrupt.h"
#include "digitalInput.h"

/**********************************************************/
#define SAMPLERATE 40000L //Hz
#define ENCODER_INC 3600
#define RADIUS_ROTOR 0.04 //m
/*********************************************************/
double nSpeed = 0.0;
double nSampleTime = 1 / SAMPLERATE;
double nEncoderRes = 360 / (ENCODER_INC*4) * DEG_TO_RAD; //rad
unsigned long nTimeInc = 0;
lcdDisplay lcdDisp;
handleInterrupt interrupt(SAMPLERATE);
digitalInput DIN2(2);
digitalInput DIN3(3);
/*********************************************************/
void setup()
{
  lcdDisp.initDisplay();
  interrupt.init();
  DIN2.init();
  DIN3.init();
}
/*********************************************************/
void loop()
{

  lcdDisp.updateSpeed(nSpeed,nTimeInc,interrupt.nCompareMatchReg);

}
/************************************************************/
ISR(TIMER1_COMPA_vect)//timer1 interrupt 500kHz
{
  DIN2.detectEdge();
  DIN3.detectEdge();

  if( DIN2.bChangedEdge || DIN3.bChangedEdge)
  {
    nSpeed = nEncoderRes / (nTimeInc * nSampleTime) * RADIUS_ROTOR; // v = w*r [m/s]
    nTimeInc = 0;
  }
  nTimeInc++;
  if( nTimeInc >= 1000000)
  {
	  nSpeed++;
	  nTimeInc = 0;

  }
}


