/*
 * digitalInput.cpp
 *
 *  Created on: 18.09.2018
 *      Author: Daniel
 */

#include "digitalInput.h"

digitalInput::digitalInput(uint8_t nPin)
{
  i_nPin = nPin;
  nStatusDIN = 0;
  nStatusDINpre = 0;
  bChangedEdge = false;
}

void digitalInput::init()
{
  pinMode(i_nPin, INPUT);
}

void digitalInput::read()
{
  nStatusDIN = digitalRead(i_nPin);
}

void digitalInput::detectEdge()
{
  nStatusDINpre = nStatusDIN;
  digitalInput::read();
  if(nStatusDIN != nStatusDINpre)
  {
	  bChangedEdge = true;
  }
}
