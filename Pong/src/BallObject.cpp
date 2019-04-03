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

BallObject::BallObject(Location location, Adafruit_SH1106& display, int radius)
  : Object(location, display), radius(radius)
{

}

BallObject::~BallObject(){}

void BallObject::Draw()
{
  this->display.fillCircle(this->location.Xpos, this->location.Ypos, radius, WHITE);
}