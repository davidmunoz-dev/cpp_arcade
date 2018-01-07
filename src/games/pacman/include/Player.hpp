//
// Player.hpp for Player in /Users/adrienmissioux/Documents/Epitech/cpp_arcade/src/games/pacman/include/
//
// Made by Adrien Missioux
// Login   <adrien.missioux@epitech.eu@epitech.eu>
//
// Started on  Sun Apr  9 17:36:48 2017 Adrien Missioux
// Last update Sun Apr  9 19:53:42 2017 Adrien Missioux
//


#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include <functional>
#include <map>
#include <vector>

class Player {
private:
  int posX;
  int posY;
  std::vector<std::string> useMap;
  std::map<int, std::function<void()> > _touch;
public:
  Player(std::vector<std::string>);
  ~Player();
  void selection(int);
  void goUp();
  void goDown();
  void goLeft();
  void goRight();
  int getPosX() const;
  int getPosY() const;
};

#endif
