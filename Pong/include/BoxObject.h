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

#include "Object.h"

#define HEIGHT (10)
#define WIDTH  (5)

class BoxObject : public Object
{
  public:
    BoxObject(Location l) : Object(l){}
    ~BoxObject();

  void Draw();

};

#endif