//
// main.cpp for ActualLib in /Users/adrienmissioux/Documents/Epitech/cpp_arcade/
//
// Made by Adrien Missioux
// Login   <adrien.missioux@epitech.eu@epitech.eu>
//
// Started on  Wed Mar 15 16:00:34 2017 Adrien Missioux
// Last update Sun Apr  9 22:41:57 2017 Adrien Missioux
//

#include "GetLib.hpp"

int main(int ac, char **av) {
  if (ac != 2) {
    std::cerr << "Usage : ./a.out [lib path].so" << std::endl;
    return (-1);
  }
  ALib *actual = new ALib(av[1]);
  GetLib *getLib = new GetLib();
  int pd = 0;
  typedef int (*hello_t)();
  hello_t makeMenu = (hello_t) actual->sym(actual->getHandle(), "makeMenu");
  pd = makeMenu();
  actual = getLib->switchAll(pd, actual);
  return (0);
}
