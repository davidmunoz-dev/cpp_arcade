/*
** Object.h for  in /home/munoz_d/Desktop/snake/include
** 
** Made by David Munoz
** Login   <david.munoz@epitech.eu>
** 
** Started on  Fri Mar 31 13:54:26 2017 David Munoz
** Last update Sat Apr  8 10:15:22 2017 David Munoz
*/

#ifndef _POSITION_H_
#define _POSITION_H_

#include <fstream>
#include <cstdlib>

typedef struct	s_coord
{
  int   x;
  int   y;
}		t_coord;

class Position
{
 public:
  Position();
  ~Position();
  void	set_posX(int x);
  void	set_posY(int y);
  int	get_posX() const;
  int	get_posY() const;  
 protected:
  t_coord	pos;
};

#endif /* _POSITION_H_ */
