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

class BallObject : public Object
{
  public:
    BallObject(Location location, int radius);
    ~BallObject();

    void Draw(Adafruit_SH1106& display);

  private:
    int radius;
};

#endif