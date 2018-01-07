//
// Map.hpp for Map in /Users/adrienmissioux/Documents/Epitech/cpp_arcade/src/games/pacman/include/
//
// Made by Adrien Missioux
// Login   <adrien.missioux@epitech.eu@epitech.eu>
//
// Started on  Tue Apr  4 12:09:48 2017 Adrien Missioux
// Last update Sun Apr  9 19:21:41 2017 Adrien Missioux
//

#ifndef _MAP_HPP_
#define _MAP_HPP_

#include <vector>
#include <iostream>

class Map {
  private:
    int _width;
    int _height;
  public:
    std::vector<std::string> _map;
    Map();
    ~Map();
    void setNewMap(int x, int y);
    int getWidth() const;
    int getHeight() const;
};

#endif
