/*
 * handleInterrupt.cpp
 *
 *  Created on: 01.09.2018
 *      Author: Daniel
 */

#include "handleInterrupt.h"

handleInterrupt::handleInterrupt(unsigned long nInterruptFreq)
:nInterruptFrequency{nInterruptFreq}
,nCompareMatchReg{0}
,nPreScaleIndex{1}
,nPreScale{1}
{}

void handleInterrupt::init()
{

  cli();//stop interrupts
  TCCR1A = 0;// set entire TCCR0A register to 0
  TCCR1B = 0;// same for TCCR0B
  TCNT1  = 0;//initialize counter value to 0

  //set timer1 interrupt at 500kHz


  // calc OCR1A
  handleInterrupt::setPreScale();
  nCompareMatchReg = (MAX_FREQUENCY / (static_cast<double>(nPreScale)*nInterruptFrequency)) -1;
  while(nCompareMatchReg >= MAX_COMPARE_VALUE && nPreScaleIndex < 5)
  {
    nPreScaleIndex++;
    handleInterrupt::setPreScale();
    nCompareMatchReg = (MAX_FREQUENCY / (static_cast<double>(nPreScale)*nInterruptFrequency)) -1;
  }

  // set compare match register for 500khz increments
  OCR1A = static_cast<int>(nCompareMatchReg);// = (16*10^6) / (1*5*10^5) - 1 (must be <65536)
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  TCCR1B |= nPreScaleBit;
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE0A);

  sei();//allow interrupts
}

void handleInterrupt::setPreScale()
{
  switch(nPreScaleIndex)
  {
    case 1:
      // bits for 1 prescaler
      nPreScaleBit = (1 << CS10);
      nPreScale = 1;
      break;

    case 2:
      // bits for 8 prescaler
      nPreScaleBit = (1 << CS11);
      nPreScale = 8;
      break;

    case 3:
      //bits for 64 prescaler
      nPreScaleBit = (1 << CS11) | (1 << CS10);
      nPreScale = 64;
      break;

    case 4:
      // bits for 256 prescaler
      nPreScaleBit = (1 << CS12);
      nPreScale = 256;
      break;

    case 5:
      // bits for 1024 prescaler
      nPreScaleBit = (1 << CS12) | (1 << CS10);
      nPreScale = 1024;
      break;
  }

}


