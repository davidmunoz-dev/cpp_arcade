//
// Position.cpp for  in /home/munoz_d/Desktop/snake/src
// 
// Made by David Munoz
// Login   <david.munoz@epitech.eu>
// 
// Started on  Fri Mar 31 13:50:03 2017 David Munoz
// Last update Sat Apr  8 10:22:27 2017 David Munoz
//

#include "Position.h"
#include <iostream>

Position::Position()
{
  pos.x = 0;
  pos.y = 0;
}

Position::~Position()
{}

void	Position::set_posX(int x)
{
  pos.x = x;
}

int	Position::get_posX() const
{
  return (pos.x);
}

void	Position::set_posY( int y )
{
  pos.y = y;
}

int	Position::get_posY() const
{
  return (pos.y);
}
