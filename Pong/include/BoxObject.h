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

#define DEFAULT_BOX_WIDTH         (display.width()/32)
#define DEFAULT_BOX_HEIGHT        (display.height()/4)
#define DEFAULT_BORDER_DISTANCE   (display.width()/16)
#define DEFAULT_STARTING_POSITION (((display.height()/2) - (DEFAULT_BOX_HEIGHT/2)))

class BoxObject : public Object
{
  public:
    BoxObject(Location location, Adafruit_SH1106& display, int width, int height);
    ~BoxObject();

    void Draw();
    void MoveUp();
    void MoveDown();

  private:
    int height;
    int width;
};

#endif