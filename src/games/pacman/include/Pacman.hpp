//
// Pacman.hpp for Pacman in /Users/adrienmissioux/Documents/Epitech/cpp_arcade/src/
//
// Made by Adrien Missioux
// Login   <adrien.missioux@epitech.eu@epitech.eu>
//
// Started on  Tue Mar 28 12:09:04 2017 Adrien Missioux
// Last update Sun Apr  9 23:19:06 2017 Adrien Missioux
//

#ifndef _PACMAN_HPP_
#define _PACMAN_HPP_

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <map>
#include <vector>
#include <functional>
#include <unistd.h>
#include <dlfcn.h>

#include "Map.hpp"
#include "Func.hpp"
#include "Player.hpp"
#include "../../IAllGames.hpp"
#include "../../../include/ALib.hpp"

class Map;

class Pacman : public IAllGames {
protected:
  Map *initMap;
public:
  Pacman();
  ~Pacman();
  void selector(arcade::CommandType);
  virtual void getWhereAmI() ;
  virtual void getMap() const;
  virtual void goUp();
  virtual void goDown();
  virtual void goLeft();
  virtual void goRight();
  virtual void goForward();
  virtual void shoot();
  virtual void illegal();
  virtual void play();
  uint16_t getPosX() const;
  uint16_t getPosY() const;
  Map *getInitMap() const;
};

extern "C" int playPacman(void * handle) {
  Func tmp(handle);
  Map  *mapInit = new Map();
  Player *pac = new Player(mapInit->_map);
  int key = 1;

  tmp.initLib();
  while (key != 0)
  {
    tmp.renderPacman(mapInit->_map);
    key = tmp.getEvent();
    pac->selection(key);
    mapInit->setNewMap(pac->getPosX(), pac->getPosY());
  }
  tmp.closeLib();

  return 0;
}

extern "C" void Play(void) {
  Pacman  pac;
  arcade::CommandType thedo = arcade::CommandType::ILLEGAL;
   while (std::cin.read((char *)&thedo, sizeof(arcade::CommandType)))
   {
     pac.selector(thedo);
   }
}

#endif
