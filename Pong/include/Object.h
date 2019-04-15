/**
 * @file Object.h
 * @author Glenn Stamminger
 * @brief 
 * @version 0.1
 * @date 2019-03-11
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef OBJECT_H
#define OBJECT_H

#include "Location.h"
#include "Adafruit_SH1106.h"

class Object
{
  public:
    Object(Location location, Adafruit_SH1106& display);
    ~Object();

    virtual void Draw() = 0;
  
  public:
    Location location;  
    Adafruit_SH1106& display;
};

#endif