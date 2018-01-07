
//
// Food_obj.cpp for  in /home/munoz_d/Desktop/snake/src
// 
// Made by David Munoz
// Login   <david.munoz@epitech.eu>
// 
// Started on  Fri Mar 31 13:48:12 2017 David Munoz
// Last update Sun Apr  9 16:12:07 2017 David Munoz
//

#include "Food_obj.h"
#include <ctime>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <map>

Food_obj::Food_obj()
{
  std::srand(time(NULL));
  eaten = true;
}

Food_obj::~Food_obj()
{}

void	Food_obj::set_food(Map& map)
{
  std::vector<t_coord> availableSpace;
  t_coord	tmp;
  int		chosenSpace;
  int		i;
  int		j;

  if (eaten)
    {
      for (i = 0; i < ROW_SIZE; ++i)
	{
	  for (j = 0; j < COL_SIZE; ++j)
	    {
	      if (map.get_symbol(j, i) == ' ')
		{
		  tmp.x = j;
		  tmp.y = i;
		  availableSpace.push_back(tmp);
		}
	    }
	}
      chosenSpace = std::rand() % availableSpace.size();
      pos.x = availableSpace[chosenSpace].x;
      pos.y = availableSpace[chosenSpace].y;
      eaten = false;
    }
}

void	Food_obj::set_eaten_state(bool state)
{
  this->eaten = state;
}

bool	Food_obj::get_eaten_state() const
{
  return (this->eaten);
}
