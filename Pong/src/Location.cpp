/**
 * @file Location.cpp
 * @author Glenn Stamminger
 * @brief 
 * @version 0.1
 * @date 2019-04-14
 * 
 * @copyright Copyright (c) 2019
 * 
 */


#include "Location.h"
//#include <cmath>

Location::Location(int Xpos, int Ypos)
	: Xpos(Xpos), Ypos(Ypos)
{

}

Location Location::operator+(const Location& velocity) const
{
	return Location(this->Xpos + velocity.Xpos, this->Ypos + velocity.Ypos);
}

Location& Location::operator+=(const Location& velocity)
{
	return *this = *this + velocity;
}

Location Location::operator-(const Location& velocity) const
{
	return Location(this->Xpos - velocity.Xpos, this->Ypos - velocity.Ypos);
}

Location& Location::operator-=(const Location& velocity)
{
	return *this = *this - velocity;
}

Location Location::operator*(int velocity) const
{
	return Location(this->Xpos * velocity, this->Ypos * velocity);
}

Location& Location::operator*=(int velocity)
{
	return *this = *this * velocity;
}