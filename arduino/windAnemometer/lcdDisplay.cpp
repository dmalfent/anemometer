/*
 * lcdDisplay.cpp
 *
 *  Created on: 01.09.2018
 *      Author: Daniel
 */

#include "lcdDisplay.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

lcdDisplay::lcdDisplay():lcd(0x27,16,2)
{
	nLcdDelayTime = 500;
	unitSpeed = "m/s";
	firstLine = "speed = ";
}

void lcdDisplay::initDisplay()
{
  lcd.init(); //initialize the lcd
  lcd.backlight(); //open the backlight
  lcdDisplay::setDisplay();
}

void lcdDisplay::setDisplay()
{
  lcd.setCursor(0,0); // set the cursor to column 15, line 0
  lcd.print(firstLine); // Print a message to the LCD.
  lcd.setCursor(13,0); // set the cursor to column 15, line 1
  lcd.print(unitSpeed);
  lcdDisplay::updateSpeed(0.0);
}

 void lcdDisplay::updateSpeed(double newSpeedValue)
{
  lcd.setCursor(8,0); // set the cursor to column 15, line 0
  lcd.print(newSpeedValue,2);
}

