/*
 * fInterrupt.h
 *
 *  Created on: 01.09.2018
 *      Author: Daniel
 */

#ifndef HANDLE_INTERRUPT_H_
#define HANDLE_INTERRUPT_H_

#include <Arduino.h>

class handleInterrupt
{
  private:

  public:
    handleInterrupt();
    void init500kHzInterrupt();
};

#endif /* HANDLE_INTERRUPT_H_ */
