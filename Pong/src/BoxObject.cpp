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

BoxObject::BoxObject(Location location, Adafruit_SH1106& display, int width, int height)
  : Object(location, display), width(width), height(height)
  {

  }

BoxObject::~BoxObject(){}

void BoxObject::Draw()
{
  this->display.fillRect(this->location.Xpos, this->location.Ypos, this->width, this->height, WHITE);
}

void BoxObject::MoveUp()
{
  if(this->location.Ypos > 0)
  {
    this->location.Ypos -= DEFAULT_STEP_SIZE;
  }
}

void BoxObject::MoveDown()
{
  if((this->location.Ypos + this->height) < display.height())
  {
    this->location.Ypos += DEFAULT_STEP_SIZE;
  }
}