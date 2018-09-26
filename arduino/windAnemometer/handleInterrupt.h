/*
 * fInterrupt.h
 *
 *  Created on: 01.09.2018
 *      Author: Daniel
 */

#ifndef HANDLE_INTERRUPT_H_
#define HANDLE_INTERRUPT_H_

#include <Arduino.h>

#define MAX_COMPARE_VALUE 65536L
#define MAX_FREQUENCY 16000000L

class handleInterrupt
{
  private:
	int nPreScaleIndex;
	unsigned long nCompareMatchReg;
	unsigned int nPreScale;
	unsigned int nPreScaleBit;
	void setPreScale();

  public:

	unsigned long nInterruptFrequency;

    handleInterrupt(unsigned long nInterruptFreq);
    void init();
};

#endif /* HANDLE_INTERRUPT_H_ */
