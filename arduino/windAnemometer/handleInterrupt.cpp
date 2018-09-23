/*
 * handleInterrupt.cpp
 *
 *  Created on: 01.09.2018
 *      Author: Daniel
 */

#include "handleInterrupt.h"

handleInterrupt::handleInterrupt()
{

}
void handleInterrupt::init500kHzInterrupt()
{
  cli();//stop interrupts

  //set timer1 interrupt at 500kHz
  TCCR1A = 0;// set entire TCCR0A register to 0
  TCCR1B = 0;// same for TCCR0B
  TCNT1  = 0;//initialize counter value to 0
  // set compare match register for 500khz increments
  OCR1A = 31;// = (16*10^6) / (1*5*10^5) - 1 (must be <65536)
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
   // CS10 bits for 1 prescaler
  TCCR1B |= (1 << CS10);
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE0A);

  sei();//allow interrupts
}


