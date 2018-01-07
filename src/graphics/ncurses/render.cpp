//
// render.cpp for render in /Users/adrienmissioux/Documents/Epitech/cpp_arcade/src/graphics/ncurses/
//
// Made by Adrien Missioux
// Login   <adrien.missioux@epitech.eu@epitech.eu>
//
// Started on  Sat Apr  8 18:28:46 2017 Adrien Missioux
// Last update Sun Apr  9 22:24:22 2017 Adrien Missioux
//

#include <iostream>
#include <vector>
#include <ncurses.h>

extern "C" int renderPacman(std::vector<std::string> initMap)
{
  int i = 0;
  int j = 0;

  std::vector<std::string> map = initMap;
  clear();
  while (i < 9)
  {
    j = 0;
    while (j < 14)
    {
      mvprintw(10 + i, 10 + j, "%c\n", map[i][j]);
      refresh();
      j++;
    }
    i++;
  }
  refresh();
  return (0);
}
