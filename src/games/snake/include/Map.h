/*
** Map.h for  in /home/munoz_d/Desktop/snake/include
** 
** Made by David Munoz
** Login   <david.munoz@epitech.eu>
** 
** Started on  Fri Mar 31 13:54:07 2017 David Munoz
** Last update Wed Apr  5 09:13:53 2017 David Munoz
*/

#ifndef _MAP_H_
#define _MAP_H_

#define	ROW_SIZE	15
#define COL_SIZE	20

class Map
{
 public:
  Map();
  ~Map();
  void clear_map();
  void set_symbol(int x, int y, unsigned char symbol);
  char get_symbol(int x, int y) const;
 private:
  char pos[ROW_SIZE][COL_SIZE];
};

#endif /* _MAP_H_ */
