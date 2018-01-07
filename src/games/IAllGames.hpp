//
// IAllGames.hpp for IAllGames in /Users/adrienmissioux/Documents/Epitech/cpp_arcade/games/include/
//
// Made by Adrien Missioux
// Login   <adrien.missioux@epitech.eu@epitech.eu>
//
// Started on  Wed Mar 29 09:03:09 2017 Adrien Missioux
// Last update Sun Apr  9 10:51:14 2017 Adrien Missioux
//

#ifndef _I_ALL_GAMES_HPP_
#define _I_ALL_GAMES_HPP_

#include <vector>
#include <map>
#include <functional>
#include "arcade_protocol.hpp"

class IAllGames {
  protected:
    arcade::GetMap  *map;
    arcade::Position  player;
    arcade::WhereAmI  *where;
    std::vector<arcade::Position> pos;
    std::map<arcade::CommandType, std::function<void()> > _choices;
  public:
    virtual void getWhereAmI() = 0;
    virtual void getMap() const = 0;
    virtual void goUp() = 0;
    virtual void goDown() = 0;
    virtual void goLeft() = 0;
    virtual void goRight() = 0;
    virtual void goForward() = 0;
    virtual void shoot() = 0;
    virtual void illegal() = 0;
    virtual void play() = 0;
};

#endif
