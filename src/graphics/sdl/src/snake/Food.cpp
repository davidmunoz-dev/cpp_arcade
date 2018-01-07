//
// Food.cpp for  in /home/munoz_d/Desktop/snake/src
// 
// Made by David Munoz
// Login   <david.munoz@epitech.eu>
// 
// Started on  Fri Mar 31 13:48:12 2017 David Munoz
// Last update Fri Apr  7 19:19:28 2017 David Munoz
//

#include "Food.h"
#include <ctime>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <map>

Food::Food()
{
  std::srand(time(NULL));	//Pour placer la pomme aléatoirement
  eaten = true;
}

Food::~Food()
{}

void Food::set_food(Map& map)
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

void	Food::set_eaten_state(bool state)
{
  this->eaten = state;
}

bool	Food::get_eaten_state() const
{
  return (this->eaten);
}
