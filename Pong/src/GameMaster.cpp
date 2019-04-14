/**
 * @file GameMaster.cpp
 * @author Glenn Stamminger
 * @brief 
 * @version 0.1
 * @date 2019-04-14
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "GameMaster.h"

GameMaster::GameMaster(BoxObject leftBox, BoxObject rightBox, BallObject ball)
  : leftBox(leftBox), rightBox(rightBox), ball(ball)
{

}

GameMaster::~GameMaster(){}

void GameMaster::DetectCollision()
{
  if(this->ball.GiveLeftSide() <= 10)
  {
    this->ball.Bounce();
  }
}
