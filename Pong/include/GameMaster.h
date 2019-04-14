/**
 * @file GameMaster.h
 * @author Glenn Stamminger
 * @brief 
 * @version 0.1
 * @date 2019-04-14
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef GAME_MASTER_H
#define GAME_MASTER_H

#include "BoxObject.h"
#include "BallObject.h"

class GameMaster
{
  public:
    GameMaster(BoxObject leftBox, BoxObject rightBox, BallObject ball);
    ~GameMaster();
    void DetectCollision();
  private:
    BoxObject leftBox;
    BoxObject rightBox;
    BallObject ball;
};

#endif