/**
 * @file BallObject.cpp
 * @author Glenn Stamminger
 * @brief 
 * @version 0.1
 * @date 2019-03-13
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "BallObject.h"

BallObject::BallObject(Location location, int radius)
  : Object(location), radius(radius)
{

}

BallObject::~BallObject(){}

void BallObject::Draw(Adafruit_SH1106& display)
{
  display.clearDisplay();
  display.fillCircle(this->location.Xpos, this->location.Ypos, radius, WHITE);
  display.display();
}