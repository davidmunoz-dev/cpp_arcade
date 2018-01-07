//
// libGra.cpp for  in /home/munoz_d/cpp_arcade/src/graphics/sdl/src/snake
//
// Made by David Munoz
// Login   <david.munoz@epitech.eu>
//
// Started on  Wed Apr  5 08:48:03 2017 David Munoz
// Last update Sun Apr  9 20:07:26 2017 David Munoz
//

#include "libGra.h"

libGra::libGra(void *handle)
{
  this->_handle = handle;
}

libGra::~libGra()
{
}

int	libGra::initLib()
{
  typedef int (*hello_t)();
  hello_t initLib = (hello_t) dlsym(this->_handle, "initLib");
  const char *dlsym_error = dlerror();
  if (dlsym_error)
    {
      std::cerr << "Cannot load symbol : " << dlsym_error << std::endl;
      throw "dlsym_error";
    }
  return (initLib());
}

int	libGra::getEvent()
{
  typedef int (*hello_t)();
  hello_t getEvent = (hello_t) dlsym(this->_handle, "getEvent");
  const char *dlsym_error = dlerror();
  if (dlsym_error)
    {
      std::cerr << "Cannot load symbol : " << dlsym_error << std::endl;
      throw "dlsym_error";
    }
  return (getEvent());
}

int	libGra::render(int foodX, int foodY, int snakeX, int snakeY, bool collision, std::string score)
{
  int (*render)(int, int, int, int, bool, std::string) = (int (*)(int, int, int, int, bool, std::string)) dlsym(this->_handle, "render");
  const char *dlsym_error = dlerror();
  if (dlsym_error)
    {
      std::cerr << "Cannot load symbol : " << dlsym_error << std::endl;
      throw "dlsym_error";
    }
  return (render(foodX, foodY, snakeX, snakeY, collision, score));
}


int	libGra::closeLib()
{
  typedef int (*hello_t)();
  hello_t closeLib = (hello_t) dlsym(this->_handle, "closeLib");
  const char *dlsym_error = dlerror();
  if (dlsym_error)
    {
      std::cerr << "Cannot load symbol : " << dlsym_error << std::endl;
      throw "dlsym_error";
    }
  return (closeLib());
}
