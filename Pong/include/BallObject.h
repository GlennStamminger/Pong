/**
 * @file BallObject.h
 * @author Glenn Stamminger
 * @brief 
 * @version 0.1
 * @date 2019-03-13
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef BALL_OBJECT_H
#define BALL_OBJECT_H

#include "Object.h"

#define BALL_RADIUS    (2)
#define BALL_VELOCITY  (1)

class BallObject : public Object
{
  public:
    BallObject(Location location, Adafruit_SH1106& display, int radius);
    ~BallObject();

    void Draw();
    void Move();
    void ScreenBounce();
    int DetectScreenEdgesX();
    int DetectScreenEdgesY();


  private:
    int radius;
    Location velocity;
};

#endif