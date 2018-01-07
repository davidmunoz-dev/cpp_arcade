//
// Game_protocole.cpp for  in /home/munoz_d/cpp_arcade/src/graphics/sdl/src/snake
//
// Made by David Munoz
// Login   <david.munoz@epitech.eu>
//
// Started on  Wed Apr  5 12:11:54 2017 David Munoz
// Last update Sun Apr  9 08:18:40 2017 Adrien Missioux
//

#include "snakeGame.h"
#include <fstream>
#include <cstdlib>
#include <iostream>

void    snakeGame::getWhereAmI() const
{
  std::cout << "where am i" << std::endl;
}

void    snakeGame::getMap() const
{
  std::cout << "getMap" << std::endl;
}

// void    snakeGame::selector(int num)
// {
//   std::cout << "selector" << std::endl;
//   this->_choices[num]();
// }

void    snakeGame::goUp()
{
  std::cout << "goUp" << std::endl;
}

void    snakeGame::goDown()
{
  std::cout << "goDown" << std::endl;
}

void    snakeGame::goLeft()
{
  std::cout << "go left" << std::endl;
}

void    snakeGame::goRight()
{
  std::cout << "go rght" << std::endl;
}

void    snakeGame::goForward()
{
  std::cout << "go forward" << std::endl;
}

void    snakeGame::shoot()
{
  std::cout << "shoot" << std::endl;
}

void    snakeGame::illegal()
{
  std::cout << "illegal" << std::endl;
}

void		snakeGame::play()
{
  std::cout << "play" << std::endl;
}

uint16_t        snakeGame::getPosX() const
{
  uint16_t	ret = 0;
  std::cout << "getPosX" << std::endl;
  return (ret);
}

uint16_t        snakeGame::getPosY() const
{
  uint16_t	ret = 0;
  std::cout << "getposY" << std::endl;
  return (ret);
}

libGra		snakeGame::getlibGra() const
{
  return (this->func);
}
