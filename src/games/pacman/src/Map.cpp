//
// Map.cpp for Map in /Users/adrienmissioux/Documents/Epitech/cpp_arcade/src/games/pacman/src/
//
// Made by Adrien Missioux
// Login   <adrien.missioux@epitech.eu@epitech.eu>
//
// Started on  Tue Apr  4 12:24:53 2017 Adrien Missioux
// Last update Sun Apr  9 19:22:01 2017 Adrien Missioux
//

#include "Map.hpp"

Map::Map() {

  this->_width = 14;
  this->_height = 9;

  this->_map.push_back("110101111101011");
  this->_map.push_back("000100010001000");
  this->_map.push_back("110111010111011");
  this->_map.push_back("710100000001017");
  this->_map.push_back("110101131101011");
  this->_map.push_back("000001333100000");
  this->_map.push_back("110101111101011");
  this->_map.push_back("7101000C0001017");
  this->_map.push_back("110101111101011");
  this->_map.push_back("000000010000000");
}

Map::~Map() {

}

void Map::setNewMap(int x, int y)
{
  int i = 0;
  int j = 0;

  while (i < 9)
  {
    j = 0;
    while (j < 14)
    {
      if (this->_map[i][j] == 'C')
        this->_map[i][j] = '0';
      j++;
    }
    i++;
  }
  this->_map[y][x] = 'C';
}

int Map::getWidth() const {
  return (this->_width);
}
int Map::getHeight() const {
  return (this->_height);
}
