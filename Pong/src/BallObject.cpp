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

BallObject::BallObject(Adafruit_SH1106& display, int radius)
  : Object(location, display), radius(radius)
{
  //Set location to center of screen.
  this->location.Xpos = display.width()/2;  
  this->location.Ypos = display.height()/2; 

  //Set ball velocity.
  this->velocity.Xpos = BALL_VELOCITY;
  this->velocity.Ypos = BALL_VELOCITY;
}

BallObject::~BallObject(){}

//Draw the ball.
void BallObject::Draw()
{
  this->display.fillCircle(this->location.Xpos, this->location.Ypos, radius, WHITE);
}

//Move the ball along the vector.
void BallObject::Move()
{
  //Check if the ball has hit the edges of the screen.
  ScreenBounce();

  this->location += this->velocity;
}

//Bounce the ball if the screen edges have been hit.
void BallObject::ScreenBounce()
{
  //If the vertical edges are hit swap the horizontal direction and move ball to center of screen.
  if((int)this->location.Xpos != DetectScreenEdgesX())
  {
    this->velocity.Xpos = -this->velocity.Xpos;
    this->location.Xpos = display.width()/2;
    this->location.Ypos = display.height()/2;
  }
  //If the horizontal edges are hit swap the vertical direction.
  if((int)this->location.Ypos != DetectScreenEdgesY())
  {
    this->velocity.Ypos = -this->velocity.Ypos;
  }
}

//Check if the vertical edges of the screen have been hit.
int BallObject::DetectScreenEdgesX()
{
  const int diameter = this->radius * 2;
  const int right = this->location.Xpos + diameter;
  //The ball has hit the left edge of the screen.
  if(this->location.Xpos < this->radius + 1)
  {
    return this->radius + 1;
  }
  //The ball has hit the right edge of the screen.
  else if(right > display.width())
  {
    return (display.width() -1) - diameter;
  }
  //The ball has not hit the left or the right edge of the screen.
  else
  {
    return this->location.Xpos;
  }
}

//Check if the horizontal edges of the screen have been hit.
int BallObject::DetectScreenEdgesY()
{
  const int diameter = this->radius * 2;
  const int bottom = this->location.Ypos + diameter;
  //The ball has hit the top edge of the screen.
  if(this->location.Ypos < this->radius + 1)
  {
    return this->radius + 1;
  }
  //The ball has hit the bottom edge of the screen.
  else if(bottom > display.height())
  {
    return (display.height() -1) - diameter;
  }
  //The ball has not hit the top or the bottom edge of the screen.
  else
  {
    return this->location.Ypos;
  }
}

//Check if the ball has hit the left box.
void BallObject::DetectLeftBoxContact(int topEdge, int bottomEdge, int sideEdge)
{
  int leftSide = this->location.Xpos - this->radius;

  //If the side of the ball is on the same vertical line as the side of the left box.
  if(leftSide == sideEdge)
  {
    //If the height of the ball is between the top and bottom of the box.
    if(this->location.Ypos >= topEdge && this->location.Ypos <= bottomEdge)
    {
      this->velocity.Xpos = -this->velocity.Xpos;
    }
  }
}

//Check if the ball has hit the rigth box.
void BallObject::DetectRightBoxContact(int topEdge, int bottomEdge, int sideEdge)
{
  int rightSide = this->location.Xpos + this->radius;

  //If the side of the ball is on the same vertical line as the side of the right box.
  if(rightSide == sideEdge)
  {
    //If the height of the ball is between the top and bottom of the box.
    if(this->location.Ypos >= topEdge && this->location.Ypos <= bottomEdge)
    {
      this->velocity.Xpos = -this->velocity.Xpos;
    }
  }
}