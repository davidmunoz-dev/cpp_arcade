/*
** Food.h for  in /home/munoz_d/Desktop/snake/include
** 
** Made by David Munoz
** Login   <david.munoz@epitech.eu>
** 
** Started on  Fri Mar 31 13:52:18 2017 David Munoz
** Last update Sat Apr  8 10:07:48 2017 David Munoz
*/

#ifndef _FOOD_OBJ_H
#define _FOOD_OBJ_H

#include "Map.h"
#include "Position.h"

class Food_obj : public Position
{
 public:
  Food_obj();
  ~Food_obj();
  void set_food(Map& myMap);
  void set_eaten_state(bool state);
  bool get_eaten_state() const;

 private:
  bool eaten;
};

#endif /* _FOOD_OBJ_H_ */
