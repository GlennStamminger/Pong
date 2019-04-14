/**
 * @file Location.h
 * @author Glenn Stamminger
 * @brief 
 * @version 0.1
 * @date 2019-03-13
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef LOCATION_H
#define LOCATION_H

class Location
{
  public:
    Location() = default;
	  Location(int Xpos, int Ypos);
	  Location operator+(const Location& velocity) const;
	  Location& operator+=(const Location& velocity);
	  Location operator-(const Location& velocity) const;
	  Location& operator-=(const Location& velocity);
  public:
    int Xpos;
    int Ypos;
};

#endif