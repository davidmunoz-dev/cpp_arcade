//
// initLib.cpp for initLib in /Users/adrienmissioux/Documents/Epitech/cpp_arcade/src/graphics/ncurses/
//
// Made by Adrien Missioux
// Login   <adrien.missioux@epitech.eu@epitech.eu>
//
// Started on  Mon Apr  3 08:54:42 2017 Adrien Missioux
// Last update Sun Apr  9 22:26:55 2017 Adrien Missioux
//

#include <ncurses.h>
#include <iostream>

extern "C" int initLib()
{
  initscr();
  noecho();
  keypad(stdscr,TRUE);
  refresh();
  return (0);
}

extern "C" int closeLib()
{
  endwin();
  return (0);
}
