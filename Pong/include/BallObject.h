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
    BallObject(Adafruit_SH1106& display, int radius);
    ~BallObject();

    void Draw();                                                            //Draw the ball.
    void Move();                                                            //Move the ball with the velocity.
    void ScreenBounce();                                                    //Ball reaction to hitting the edges of the screen.
    int DetectScreenEdgesX();                                               //Detect if the ball hit the vertical edges of the screen.
    int DetectScreenEdgesY();                                               //Detect if the ball hit the horizontal edges of the screen.
    void DetectLeftBoxContact(int topEdge, int bottomEdge, int sideEdge);   //Detect if the ball has hit the left box.
    void DetectRightBoxContact(int topEdge, int bottomEdge, int sideEdge);  //Detect if the ball has hit the right box.

  private:
    int radius;
    Location velocity;
};

#endif