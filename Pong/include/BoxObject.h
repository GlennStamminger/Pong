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

//BOX sizes based on 128x64 OLED display.

#define BOX_BOX_WIDTH         (4) //Width divided by 32.
#define BOX_BOX_HEIGHT        (16) //Height divided by 4.
#define BOX_BORDER_DISTANCE   (8) //Width divided 16.
#define BOX_STARTING_POSITION (32 - (BOX_BOX_HEIGHT/2)) //Height divided by 2 - the BOX_BOX_HEIGHT divided by 2
#define BOX_STEP_SIZE         (2)

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