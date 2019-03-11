/**
 * @file IBoxObject.h
 * @author Glenn Stamminger
 * @brief 
 * @version 0.1
 * @date 2019-03-11
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef BOX_OBJECT_H
#define BOX_OBJECT_H

#include "IObject.h"

class BoxObject : IObject
{
  public:

  BoxObject(int Xpos, int Ypos, int height, int width);
  
  ~BoxObject();

  void Draw(int Xpos, int Ypos, int height, int width);

};

#endif