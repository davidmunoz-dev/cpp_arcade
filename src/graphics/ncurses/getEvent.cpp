#include <ncurses.h>
#include <iostream>

extern "C" int getEvent()
{
  int key = 0;
  key=getch();
  switch(key) {
          case  50:
            return 7;
          case  51:
            return 8;
          case  52:
            return 9;
          case  53:
            return 10;
          case  56:
            return 11;
          case  57:
            return 12;
          case KEY_UP:
            return 2;
          case KEY_DOWN:
            return 3;
          case KEY_LEFT:
            return 4;
          case KEY_RIGHT:
            return 5;
          case 27:
            return 0;
      }
    return (key);
}
