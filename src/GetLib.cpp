//
// GetLib.cpp for GetLib in /Users/adrienmissioux/Documents/Epitech/cpp_arcade/
//
// Made by Adrien Missioux
// Login   <adrien.missioux@epitech.eu@epitech.eu>
//
// Started on  Sat Mar 18 10:37:50 2017 Adrien Missioux
// Last update Sun Apr  9 22:45:27 2017 Adrien Missioux
//

#include "GetLib.hpp"

GetLib::GetLib() {

_choices.insert(std::make_pair(0, std::bind(&GetLib::goPreviousLib, this, std::placeholders::_1)));
_choices.insert(std::make_pair(1, std::bind(&GetLib::goNextLib, this, std::placeholders::_1)));
_choices.insert(std::make_pair(2, std::bind(&GetLib::goPreviousGame, this, std::placeholders::_1)));
_choices.insert(std::make_pair(3, std::bind(&GetLib::goNextGame, this, std::placeholders::_1)));
_choices.insert(std::make_pair(4, std::bind(&GetLib::goExit, this, std::placeholders::_1)));
_choices.insert(std::make_pair(10, std::bind(&GetLib::goPacman, this, std::placeholders::_1)));
_choices.insert(std::make_pair(11, std::bind(&GetLib::goSnake, this, std::placeholders::_1)));

}

GetLib::~GetLib() {
}

ALib *GetLib::switchAll(int num, ALib * actual) {
  return (_choices[num](actual));
}

ALib  *GetLib::goPreviousLib(ALib * actual) {
  int tmp = 0;
  int tmpG = actual->getNumGame();
  bool whatElse = actual->getStatu();

  if (actual->getNumLib() == 0)
    tmp = actual->getAllLib().size() - 1;
  else
    tmp = actual->getNumLib() - 1;
  ALib *newOne = new ALib(actual->getAllLib().at(tmp));
  newOne->setNumLib(tmp);
  newOne->setNumGame(tmpG);
  if (whatElse == false)
    {
      typedef int (*hello_t)();
      hello_t makeMenu = (hello_t) newOne->sym(newOne->getHandle(), "makeMenu");
      return (this->switchAll(makeMenu(), newOne));
    }
  return (newOne);
}

ALib  *GetLib::goNextLib(ALib * actual) {
  int tmp = 0;
  int tmpG = actual->getNumGame();
  bool whatElse = actual->getStatu();

  if ((unsigned int)actual->getNumLib() == actual->getAllLib().size() - 1)
    tmp = 0;
  else
    tmp = actual->getNumLib() + 1;
  ALib *newOne = new ALib(actual->getAllLib().at(tmp));
  newOne->setNumLib(tmp);
  newOne->setNumGame(tmpG);
  if (whatElse == false)
    {
      typedef int (*hello_t)();
      hello_t makeMenu = (hello_t) newOne->sym(newOne->getHandle(), "makeMenu");
      return (this->switchAll(makeMenu(), newOne));
    }
  else {
    newOne->setHandleGame(newOne->load(newOne->getAllGames().at(tmpG)));
    newOne->setNumGame(tmpG);
    if (tmpG == 0) {
      int (*init)(void *) = (int (*)(void *)) newOne->sym(newOne->getHandleGame(), "playPacman");
      return this->switchAll(init(newOne->getHandle()), newOne);
    }
    else {
        int (*init)(void *) = (int (*)(void *)) newOne->sym(newOne->getHandleGame(), "playSnake");
        return this->switchAll(init(newOne->getHandle()), newOne);
    }
  }
  return (newOne);
}

ALib  *GetLib::goPreviousGame(ALib * actual) {
  int tmp = actual->getNumGame();
  if (actual->getHandleGame())
    dlclose(actual->getHandleGame());
  if (tmp == 0)
  {
    tmp++;
    actual->setHandleGame(actual->load(actual->getAllGames().at(tmp)));
    actual->setNumGame(tmp);
  }
  else
  {
    tmp--;
    actual->setHandleGame(actual->load(actual->getAllGames().at(tmp)));
    actual->setNumGame(tmp);
  }
  return (actual);
}

ALib  *GetLib::goNextGame(ALib * actual) {
  int tmp = actual->getNumGame();

  if (actual->getHandleGame())
    dlclose(actual->getHandleGame());
  if (tmp == 0)
  {
    tmp++;
    actual->setHandleGame(actual->load(actual->getAllGames().at(tmp)));
    actual->setNumGame(tmp);
  }
  else
  {
    tmp--;
    actual->setHandleGame(actual->load(actual->getAllGames().at(tmp)));
    actual->setNumGame(tmp);
  }
  return (actual);
}

ALib  *GetLib::goExit(ALib * actual) {
  (void)actual;
  return (actual);
}


ALib  *GetLib::goSnake(ALib * actual) {

  actual->setHandleGame(actual->load("./games/lib_arcade_snake.so"));
  actual->setNumGame(1);
  int (*init)(void *) = (int (*)(void *)) actual->sym(actual->getHandleGame(), "playSnake");
  return this->switchAll(init(actual->getHandle()), actual);
}
ALib  *GetLib::goPacman(ALib * actual) {
  actual->setHandleGame(actual->load("./games/lib_arcade_pacman.so"));
  actual->setNumGame(0);
  int (*init)(void *) = (int (*)(void *)) actual->sym(actual->getHandleGame(), "playPacman");
  return this->switchAll(init(actual->getHandle()), actual);
}
