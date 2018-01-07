//
// Map.cpp for  in /home/munoz_d/Desktop/snake/src
// 
// Made by David Munoz
// Login   <david.munoz@epitech.eu>
// 
// Started on  Fri Mar 31 13:49:50 2017 David Munoz
// Last update Fri Mar 31 13:49:55 2017 David Munoz
//

#include "Map.h"
#include <iostream>

Map::Map()
{
  clear_map();
}

Map::~Map()
{
}

void	Map::clear_map()
{
  for (int i = 0; i < ROW_SIZE; ++i)
    for (int j = 0; j < COL_SIZE; ++j)
      pos[i][j] = ' ';
}

void	Map::set_symbol(int x, int y, unsigned char symbol)
{
  pos[y][x] = symbol;
}

char	Map::get_symbol(int x, int y) const
{
  return (pos[y][x]);
}
