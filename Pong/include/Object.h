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

struct Location
{
  int Xpos;
  int Ypos;
};

class Object
{
  public:
    Object();
    Object(Location l){};
    ~Object();

    virtual void Draw() = 0;
  
  protected:
    Location l;  
};

#endif