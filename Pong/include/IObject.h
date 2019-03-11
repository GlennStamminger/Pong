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

#ifndef I_OBJECT_H
#define I_OBJECT_H

class IObject
{
  public:

    virtual ~IObject() {}

    virtual void Draw() = 0;
  
  private:

    int *Xpos; //Position on X axis
    int *Ypos; //Position on Y axis
};

#endif