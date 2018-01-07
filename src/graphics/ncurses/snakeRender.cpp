//
// snakeRender.cpp for snakerender in /home/onillo_l/cpp_arcade/src/graphics/ncurses
// 
// Made by Lucas ONILLON
// Login   <onillo_l@epitech.net>
// 
// Started on  Sun Apr  9 20:29:44 2017 Lucas ONILLON
// Last update Sun Apr  9 22:32:40 2017 Lucas ONILLON
//

#include <iostream>
#include <vector>
#include <ncurses.h>

# define	WIDTH		(20)
# define	HEIGHT		(15)
# define	BORDER_T	"|"
# define	BORDER		"--------------------"

void		draw_map()
{
  int		x, y;

  x = y = 0;
  clear();
  mvprintw(0, 0, BORDER);
  while (x <= HEIGHT)
    {
      while (y <= WIDTH)
	{
	  if (y == 0 || y == WIDTH)
	    mvprintw(x, y, BORDER_T);
	  y++;
	}
      x++;
      y = 0;
    }
  mvprintw(HEIGHT, 0, BORDER);
}

extern "C" int		render(int snakeX, int snakeY, int foodX, int foodY, bool is_over, std::string score)
{
  if (is_over == true)
    {
      if (score.empty())
	mvprintw(0, 0, "GAME OVER");
      else
	mvprintw(0, 0, "GAME OVER: score -> %s\n", score);
      return (0);
    }
  draw_map();
  mvprintw(snakeX, snakeY, "S");
  mvprintw(foodX, foodY, "F");
  if (score.empty())
    mvprintw(HEIGHT + 1, 0, "score: NONE\n");
  else
    mvprintw(HEIGHT + 1, 0, "score: %s\n", score);
  return (0);
}
