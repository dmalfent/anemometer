/*
 * digitalInput.h
 *
 *  Created on: 18.09.2018
 *      Author: Daniel
 */

#ifndef DIGITALINPUT_H_
#define DIGITALINPUT_H_


#include <Arduino.h>

class digitalInput
{
  private:
	uint8_t i_nPin;

  public:

	uint8_t nStatusDIN;
	uint8_t nStatusDINpre;
	bool bChangedEdge;
	digitalInput(uint8_t nPin);
    void init();
    void read();
    void detectEdge();
};

#endif /* DIGITALINPUT_H_ */
