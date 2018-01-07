//
// Pacman.cpp for Pacman in /Users/adrienmissioux/Documents/Epitech/cpp_arcade/src/
//
// Made by Adrien Missioux
// Login   <adrien.missioux@epitech.eu@epitech.eu>
//
// Started on  Tue Mar 28 12:09:43 2017 Adrien Missioux
// Last update Sun Apr  9 23:16:57 2017 Adrien Missioux
//

#include "Pacman.hpp"
#include <dlfcn.h>

Pacman::Pacman() {

  // initial map
  this->initMap = new Map();

  // GetMap struct
  this->map = (arcade::GetMap *)malloc(sizeof(arcade::GetMap) + (sizeof(arcade::TileType) * this->initMap->getHeight() * this->initMap->getWidth()));
  this->map->width = this->initMap->getWidth();
  this->map->height = this->initMap->getHeight();
  this->map->type = arcade::CommandType::GET_MAP;
  size_t i = 0;
  while (i < 9)
  {
    size_t j = 0 ;
    while (j < 14)
    {
      if (this->initMap->_map[i][j] == '0')
        this->map->tile[j * 9 + i] = arcade::TileType::EMPTY;
      else if (this->initMap->_map[i][j] == '1')
        this->map->tile[j * this->map->height + i] = arcade::TileType::BLOCK;
      else
        this->map->tile[j * this->map->height + i] = arcade::TileType::OTHER;
      j++;
    }
    i++;
  }
  // Position struct
  this->player.x = 7;
  this->player.y = 2;
  this->pos.push_back(this->player);
  // WhereAmI struct
  this->where = (arcade::WhereAmI *)malloc(sizeof(arcade::WhereAmI));
  this->where->type = arcade::CommandType::WHERE_AM_I;

  _choices.insert(std::make_pair(arcade::CommandType::WHERE_AM_I, std::bind(&Pacman::getWhereAmI, this)));
  _choices.insert(std::make_pair(arcade::CommandType::GET_MAP, std::bind(&Pacman::getMap, this)));
  _choices.insert(std::make_pair(arcade::CommandType::GO_UP, std::bind(&Pacman::goUp, this)));
  _choices.insert(std::make_pair(arcade::CommandType::GO_DOWN, std::bind(&Pacman::goDown, this)));
  _choices.insert(std::make_pair(arcade::CommandType::GO_LEFT, std::bind(&Pacman::goLeft, this)));
  _choices.insert(std::make_pair(arcade::CommandType::GO_RIGHT, std::bind(&Pacman::goRight, this)));
  _choices.insert(std::make_pair(arcade::CommandType::GO_FORWARD, std::bind(&Pacman::goForward, this)));
  _choices.insert(std::make_pair(arcade::CommandType::SHOOT, std::bind(&Pacman::shoot, this)));
  _choices.insert(std::make_pair(arcade::CommandType::ILLEGAL, std::bind(&Pacman::illegal, this)));
  _choices.insert(std::make_pair(arcade::CommandType::PLAY, std::bind(&Pacman::play, this)));
}

Pacman::~Pacman() {}

void Pacman::selector(arcade::CommandType num) {
  this->_choices[num]();
}

void Pacman::getWhereAmI() {
    arcade::WhereAmI  *where;
    where = (arcade::WhereAmI *)malloc(sizeof(arcade::WhereAmI) + (this->pos.size() * sizeof(arcade::Position)));
    where->type = arcade::CommandType::WHERE_AM_I;
    int i = 0;
    where->lenght = this->pos.size();
    for (std::vector<arcade::Position>::const_iterator it = this->pos.begin() ; it != this->pos.end(); ++it)
      where->position[i] = *it;
    write(1, where, sizeof(arcade::WhereAmI) + (this->pos.size() * sizeof(arcade::Position)));
    free(where);
}
void  Pacman::getMap() const {
    arcade::GetMap *_mapTmp;
    _mapTmp = (arcade::GetMap *)malloc(sizeof(arcade::GetMap) + (sizeof(arcade::TileType) * this->initMap->getHeight() * this->initMap->getWidth()));
    _mapTmp->width = this->initMap->getWidth();
    _mapTmp->height = this->initMap->getHeight();
    _mapTmp->type = arcade::CommandType::GET_MAP;
    size_t i = 0;
    while (i < 9)
    {
      size_t j = 0 ;
      while (j < 14)
      {
        if (this->initMap->_map[i][j] == '0')
          _mapTmp->tile[j * _mapTmp->height + i] = arcade::TileType::EMPTY;
        else if (this->initMap->_map[i][j] == '1')
          _mapTmp->tile[j * _mapTmp->height + i] = arcade::TileType::BLOCK;
        else
          _mapTmp->tile[j * _mapTmp->height + i] = arcade::TileType::OTHER;
        j++;
      }
      i++;
    }
    write(1, _mapTmp, sizeof(arcade::GetMap) + (sizeof(arcade::TileType) * 14 * 9));
    free(_mapTmp);
}
void Pacman::goUp() {
  if (this->initMap->_map[this->player.y++][this->player.x] == '0')
  {
    if (this->player.y != this->map->height)
      this->player.y++;
  }
  this->pos.push_back(this->player);
}
void Pacman::goDown() {
  if (this->initMap->_map[this->player.y--][this->player.x] == '0')
  {
    if (this->player.y != 0)
      this->player.y--;
  }
  this->pos.push_back(this->player);
}
void Pacman::goLeft() {
  if (this->initMap->_map[this->player.y][this->player.x--] == '0')
  {
    if (this->player.x != 0)
      this->player.x--;
  }
  this->pos.push_back(this->player);
}
void Pacman::goRight() {
  if (this->initMap->_map[this->player.y][this->player.x++] == '0')
  {
    if (this->player.x != this->map->width)
      this->player.x++;
  }
  this->pos.push_back(this->player);
}
void Pacman::goForward() {
}
void Pacman::shoot() {
}
void Pacman::illegal() {
}
void Pacman::play() {
  Play();
}

uint16_t Pacman::getPosX() const {
  return (this->player.x);
}
uint16_t Pacman::getPosY() const {
  return (this->player.y);
}

Map *Pacman::getInitMap() const {
  return(this->initMap);
}
