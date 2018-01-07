/*
** Object.h for  in /home/munoz_d/Desktop/snake/include
** 
** Made by David Munoz
** Login   <david.munoz@epitech.eu>
** 
** Started on  Fri Mar 31 13:54:26 2017 David Munoz
** Last update Mon Apr  3 14:44:11 2017 David Munoz
*/

#ifndef OBJECT_H
#define OBJECT_H

#include "SDL2/SDL.h"
#include "LTexture.h"
#include <fstream>
#include <cstdlib>

typedef struct	s_coord
{
  int   x;
  int   y;
}		t_coord;

class Object
{
 public:
  Object();
  ~Object();
  void	set_posX(int x);
  void	set_posY(int y);
  int	get_posX() const;
  int	get_posY() const;  
  LTexture texture;
 protected:
  t_coord	pos;
};

#endif // OBJECT_H
