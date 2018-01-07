//
// GetLib.hpp for GetLib in /Users/adrienmissioux/Documents/Epitech/cpp_arcade/
//
// Made by Adrien Missioux
// Login   <adrien.missioux@epitech.eu@epitech.eu>
//
// Started on  Sat Mar 18 10:32:51 2017 Adrien Missioux
// Last update Sun Apr  9 21:46:59 2017 Adrien Missioux
//

#ifndef _GETLIB_HPP_
#define _GETLIB_HPP_

#include <utility>
#include <map>
#include <functional>

#include "ALib.hpp"

class ALib;

class GetLib {

public:
  GetLib();
  ~GetLib();
  ALib *switchAll(int num, ALib *act);
private:
  std::map<int, std::function<ALib *(ALib *)> > _choices;

  ALib  *goPreviousLib(ALib *);
  ALib  *goNextLib(ALib *);
  ALib  *goPreviousGame(ALib *);
  ALib  *goNextGame(ALib *);
  ALib  *goExit(ALib *);
  ALib  *goSnake(ALib *);
  ALib  *goPacman(ALib *);
};

#endif
