/*
** Food.h for  in /home/munoz_d/Desktop/snake/include
** 
** Made by David Munoz
** Login   <david.munoz@epitech.eu>
** 
** Started on  Fri Mar 31 13:52:18 2017 David Munoz
** Last update Mon Apr  3 14:38:37 2017 David Munoz
*/

#ifndef _FOOD_H
#define _FOOD_H

#include "Map.h"
#include "Object.h"

class Food : public Object
{
 public:
  Food();
  ~Food();
  void set_food(Map& myMap);
  void set_eaten_state(bool state);
  bool get_eaten_state() const;
	
 private:
  bool eaten;
};

#endif /* _FOOD_H_ */
