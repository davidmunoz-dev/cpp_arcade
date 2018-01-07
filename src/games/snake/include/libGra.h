/*
** Func.h for Func in /Users/adrienmissioux/Documents/Epitech/cpp_arcade/src/games/snake/include/
**
** Made by Adrien Missioux
** Login   <adrien.missioux@epitech.eu@epitech.eu>
**
** Started on  Sat Apr  1 16:44:18 2017 Adrien Missioux
** Last update Sun Apr  9 19:08:03 2017 David Munoz
*/

#ifndef _LIBGRA_H_
#define _LIBGRA_H_

#include "../../../include/ALib.hpp"

class	ALib;

class libGra
{
  void	*_handle;
 public:
  libGra(void *);
  ~libGra();
  int	initLib();
  int	getEvent();
  int	render(int, int, int, int, bool, std::string);
  int	closeLib();
};

#endif	/* _LIBGRA_H_ */
