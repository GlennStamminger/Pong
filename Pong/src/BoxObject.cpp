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

//Draw the box.
void BoxObject::Draw()
{
  if(this->location.Xpos + this->width <= display.width())
  {
    this->display.fillRect(this->location.Xpos, this->location.Ypos, this->width, this->height, WHITE);
  }
  else
  {
    this->display.fillRect(display.width() - this->width, this->location.Ypos, this->width, this->height, WHITE);
  }
}

//Move the box up.
void BoxObject::MoveUp()
{
  //Check if the box will not go off screen.
  if(this->location.Ypos > 0)
  {
    this->location.Ypos -= BOX_STEP_SIZE;
  }
}

//Move the box down.
void BoxObject::MoveDown()
{
  //Check if the box will not go off screen.
  if((this->location.Ypos + this->height) < display.height())
  {
    this->location.Ypos += BOX_STEP_SIZE;
  }
}