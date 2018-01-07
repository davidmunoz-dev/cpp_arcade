//
// Sdl.hpp for Sdl in /Users/adrienmissioux/Documents/Epitech/cpp_arcade/
//
// Made by Adrien Missioux
// Login   <adrien.missioux@epitech.eu@epitech.eu>
//
// Started on  Sat Mar 18 10:27:44 2017 Adrien Missioux
// Last update Wed Mar 22 17:25:59 2017 hazer
//

#ifndef _SDL_HPP_
#define _SDL_HPP_

#include "ALib.hpp"
#include "SDL2/SDL.h"

class Sdl : public ALib {
public:
  Sdl(const std::string & path);
  virtual void *init();
};

#endif
