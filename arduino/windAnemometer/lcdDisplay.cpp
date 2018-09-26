/*
 * lcdDisplay.cpp
 *
 *  Created on: 01.09.2018
 *      Author: Daniel
 */

#include "lcdDisplay.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

lcdDisplay::lcdDisplay()
:lcd(0x27,16,2)
,nLcdDelayTime{500}
,cUnitSpeed{"m/s"}
,cFirstLine{"speed = "}
{}

void lcdDisplay::initDisplay()
{
  lcd.init(); //initialize the lcd
  lcd.backlight(); //open the backlight
  lcdDisplay::setDisplay();
}

void lcdDisplay::setDisplay()
{
  lcd.setCursor(0,0); // set the cursor to column 15, line 0
  lcd.print(cFirstLine); // Print a message to the LCD.
  lcd.setCursor(13,0); // set the cursor to column 15, line 1
  lcd.print(cUnitSpeed);
}

 void lcdDisplay::updateSpeed(double& newSpeedValue,long index,long preFactor)
{
  lcd.setCursor(8,0); // set the cursor to column 15, line 0
  lcd.print(newSpeedValue,2);
  lcd.setCursor(0,1);
  lcd.print(index);
  lcd.setCursor(9,1);
  lcd.print(preFactor);
}

