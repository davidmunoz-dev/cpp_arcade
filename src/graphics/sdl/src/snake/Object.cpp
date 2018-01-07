//
// Object.cpp for  in /home/munoz_d/Desktop/snake/src
// 
// Made by David Munoz
// Login   <david.munoz@epitech.eu>
// 
// Started on  Fri Mar 31 13:50:03 2017 David Munoz
// Last update Fri Mar 31 13:50:18 2017 David Munoz
//

#include "Object.h"

Object::Object()
{
    pos.x = 0;
    pos.y = 0;
}

Object::~Object()
{}

void	Object::set_posX(int x)
{
  pos.x = x;
}

int Object::get_posX() const
{
  return (pos.x);
}

void Object::set_posY( int y )
{
  pos.y = y;
}

int Object::get_posY() const
{
  return (pos.y);
}
