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

class BoxObject : public Object
{
  public:
    BoxObject(Location location, int height, int width);
    ~BoxObject();

    void Draw(Adafruit_SH1106& display);

  private:
    int height;
    int width;
};

#endif