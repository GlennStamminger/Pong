/**
 * @file Object.cpp
 * @author Glenn Stamminger
 * @brief 
 * @version 0.1
 * @date 2019-03-13
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "Object.h"

Object::Object(Location location, Adafruit_SH1106& display)
  : location(location), display(display)
{

}

Object::~Object(){}