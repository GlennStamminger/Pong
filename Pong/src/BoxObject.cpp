/**
 * @file BoxObject.cpp
 * @author Glenn Stamminger
 * @brief 
 * @version 0.1
 * @date 2019-03-13
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "BoxObject.h"

BoxObject::BoxObject(Location Location, int height, int width)
  : Object(location), height(height), width(width)
{
 
}

BoxObject::~BoxObject(){}

void BoxObject::Draw(Adafruit_SH1106& display)
{
  display.fillRect(this->location.Xpos, this->location.Ypos, this->height, this->width, WHITE);
}