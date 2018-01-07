//
// Ncurses.hpp for Ncurses in /Users/adrienmissioux/Documents/Epitech/cpp_arcade/
//
// Made by Adrien Missioux
// Login   <adrien.missioux@epitech.eu@epitech.eu>
//
// Started on  Sat Mar 18 10:14:32 2017 Adrien Missioux
// Last update Sat Mar 18 10:23:20 2017 Adrien Missioux
//

#ifndef _NCURSES_HPP_
#define _NCURSES_HPP_

#include "ALib.hpp"

class Ncurses : public ALib {
public:
  Ncurses(const std::string & path);
  virtual void *init();
};

#endif
