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
  this->velocity.Xpos = BALL_VELOCITY;
  this->velocity.Ypos = BALL_VELOCITY;
}

BallObject::~BallObject(){}

void BallObject::Draw()
{
  this->display.fillCircle(this->location.Xpos, this->location.Ypos, radius, WHITE);
}

void BallObject::Move()
{
  ScreenBounce();
  this->location += this->velocity;
}

void BallObject::ScreenBounce()
{
  if((int)this->location.Xpos != DetectScreenEdgesX())
  {
    this->velocity.Xpos = -this->velocity.Xpos;
  }
  if((int)this->location.Ypos != DetectScreenEdgesY())
  {
    this->velocity.Ypos = -this->velocity.Ypos;
  }
}

int BallObject::DetectScreenEdgesX()
{
  const int diameter = this->radius * 2;
  const int right = this->location.Xpos + diameter;
  if(this->location.Xpos < this->radius + 1)
  {
    return this->radius + 1;
  }
  else if(right > display.width())
  {
    return (display.width() -1) - diameter;
  }
  else
  {
    return this->location.Xpos;
  }
}

int BallObject::DetectScreenEdgesY()
{
  const int diameter = this->radius * 2;
  const int bottom = this->location.Ypos + diameter;
  if(this->location.Ypos < this->radius + 1)
  {
    return this->radius + 1;
  }
  else if(bottom > display.height())
  {
    return (display.height() -1) - diameter;
  }
  else
  {
    return this->location.Ypos;
  }
}