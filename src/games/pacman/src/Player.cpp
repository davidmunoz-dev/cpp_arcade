//
// Player.cpp for Player in /Users/adrienmissioux/Documents/Epitech/cpp_arcade/src/games/pacman/src/
//
// Made by Adrien Missioux
// Login   <adrien.missioux@epitech.eu@epitech.eu>
//
// Started on  Sun Apr  9 17:57:47 2017 Adrien Missioux
// Last update Sun Apr  9 22:35:13 2017 Adrien Missioux
//

#include "Player.hpp"

Player::Player(std::vector<std::string> tmp) {
  this->useMap = tmp;
  this->posX = 7;
  this->posY = 7;
  _touch.insert(std::make_pair(2, std::bind(&Player::goUp, this)));
  _touch.insert(std::make_pair(3, std::bind(&Player::goDown, this)));
  _touch.insert(std::make_pair(4, std::bind(&Player::goLeft, this)));
  _touch.insert(std::make_pair(5, std::bind(&Player::goRight, this)));
}

Player::~Player() {}

void Player::selection(int num)
{
  _touch[num]();
}

void Player::goUp() {
  // if (this->useMap[this->posY--][this->posX] == '0' && this->posY-- > 0)
  //   this->posY--;
}
void Player::goDown() {
  // if (this->useMap[this->posY++][this->posX] == '0' && this->posY++ < 10)
  //   this->posY++;
}
void Player::goLeft() {
  // if (this->useMap[this->posY][this->posX--] == '0' && this->posX-- > 0)
  //   this->posX--;
}
void Player::goRight() {
  // if (this->useMap[this->posY][this->posX++] == '0' && this->posX++ < 10)
  //   this->posX++;
}

int Player::getPosX() const {
  return this->posX;
}
int Player::getPosY() const {
  return this->posY;
}
