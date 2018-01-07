//
// Func.cpp for Func in /Users/adrienmissioux/Documents/Epitech/cpp_arcade/src/games/pacman/src/
//
// Made by Adrien Missioux
// Login   <adrien.missioux@epitech.eu@epitech.eu>
//
// Started on  Tue Apr  4 15:32:43 2017 Adrien Missioux
// Last update Sun Apr  9 23:20:17 2017 Adrien Missioux
//

#include "Func.hpp"

Func::Func(void *handle) {
  this->_handle = handle;
}

Func::~Func() {
}

int Func::initLib() {
  typedef int (*hello_t)();
  hello_t init = (hello_t) dlsym(this->getHandle(), "initLib");
  const char *dlsym_error = dlerror();
  if (dlsym_error)
  {
    std::cerr << "Cannot load symbol : " << dlsym_error << std::endl;
    throw "dlsym_error";
  }
  return (init());
}

int Func::closeLib() {
  typedef int (*hello_t)();
  hello_t init = (hello_t) dlsym(this->getHandle(), "closeLib");
  const char *dlsym_error = dlerror();
  if (dlsym_error)
  {
    std::cerr << "Cannot load symbol : " << dlsym_error << std::endl;
    throw "dlsym_error";
  }
  return (init());
}

int Func::renderPacman(std::vector<std::string> initMap) {
  int (*render)(std::vector<std::string>) = (int (*)(std::vector<std::string>)) dlsym(this->getHandle(), "renderPacman");
  const char *dlsym_error = dlerror();
  if (dlsym_error)
  {
    std::cerr << "Cannot load symbol : " << dlsym_error << std::endl;
    throw "dlsym_error";
  }
  return (render(initMap));
}

int Func::getEvent() {
  typedef int (*hello_t)();
  hello_t getEvent = (hello_t) dlsym(this->getHandle(), "getEvent");
  const char *dlsym_error = dlerror();
  if (dlsym_error)
  {
    std::cerr << "Cannot load symbol : " << dlsym_error << std::endl;
    throw "dlsym_error";
  }
  return (getEvent());
}

void *Func::getHandle() const {
  return (this->_handle);
}
