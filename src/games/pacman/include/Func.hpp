/*
** Func.h for Func in /Users/adrienmissioux/Documents/Epitech/cpp_arcade/src/games/snake/include/
**
** Made by Adrien Missioux
** Login   <adrien.missioux@epitech.eu@epitech.eu>
**
** Started on  Sat Apr  1 16:44:18 2017 Adrien Missioux
// Last update Sun Apr  9 23:20:48 2017 Adrien Missioux
*/

#ifndef _FUNC_HPP_
#define _FUNC_HPP_

#include "../../../include/ALib.hpp"
#include <dlfcn.h>
#include <vector>

class ALib;

class Func
{
private:
  void *_handle;
 public:
  Func(void *);
  ~Func();
  int initLib();
  int closeLib();
  int renderPacman(std::vector<std::string>);
  int getEvent();
  void *getHandle() const;
};

#endif
