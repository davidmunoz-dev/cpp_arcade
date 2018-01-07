//
// Game_collision.cpp for  in /home/munoz_d/Desktop/snake/src
//
// Made by David Munoz
// Login   <david.munoz@epitech.eu>
//
// Started on  Fri Mar 31 13:48:31 2017 David Munoz
// Last update Sun Apr  9 19:31:32 2017 David Munoz
//

#include "snakeGame.h"
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>

//	Fonction pour convertir un int en string
//	sinon erreur de compile avec celui de base
template <typename T>
std::string to_string(T value)
{
  std::ostringstream	os;
  os << value;
  return (os.str());
}

std::string	snakeGame::get_score() const
{
  return (this->str_score);
}

void	snakeGame::set_score(std::string _score)
{
  this->str_score = _score;
}

void	snakeGame::collision_right()
{
  if (snake.get_frontX() + 1 == COL_SIZE)
    snake.set_collision_state( true );
  else if ((snake.get_frontX() + 1 == food.get_posX())&&
           (snake.get_frontY() == food.get_posY()))
    {
      food.set_eaten_state(true);
      snake.grow();
    }
  else
    snake.move();
}

void	snakeGame::collision_left()
{
  if (snake.get_frontX() - 1 == -1)
    snake.set_collision_state(true);
  else if ((snake.get_frontX() - 1 == food.get_posX()) &&
           (snake.get_frontY() == food.get_posY()))
    {
      food.set_eaten_state(true);
      snake.grow();
    }
  else
    snake.move();
}

void	snakeGame::collision_up()
{
  if (snake.get_frontY() - 1 == -1)
    snake.set_collision_state(true);
  else if ((snake.get_frontY() - 1 == food.get_posY()) &&
           (snake.get_frontX() == food.get_posX()))
    {
      food.set_eaten_state(true);
      snake.grow();
    }
  else
    snake.move();
}

void	snakeGame::collision_down()
{
  if (snake.get_frontY() + 1 == ROW_SIZE)
    snake.set_collision_state(true);
  else if ((snake.get_frontY() + 1 == food.get_posY()) &&
           (snake.get_frontX() == food.get_posX()))
    {
      food.set_eaten_state(true);
      snake.grow();
    }
  else
    snake.move();
}

//	Main fonction des collisions
void	snakeGame::collision(Map map)
{
  int   i;

  if (snake.get_collision_state() == false)
    {
      if (snake.get_direction() == GO_RIGHT)
        collision_right();
      else if (snake.get_direction() == GO_LEFT)
        collision_left();
      else if (snake.get_direction() == GO_UP)
       collision_up();
      else if(snake.get_direction() == GO_DOWN)
        collision_down();
    }
  set_score(to_string(snake.length() - 1));
  for (i = 0; i < snake.length(); ++i)
    map.set_symbol(snake.get_posX(i), snake.get_posY(i), SNAKE);
  food.set_food(map);
  map.set_symbol(food.get_posX(), food.get_posY(), APPLE);
}

extern "C" void Play(void) {
  snakeGame lol;

  arcade::CommandType thedo = arcade::CommandType::ILLEGAL;
   while (std::cin.read((char *)&thedo, sizeof(arcade::CommandType)))
   {
     lol.selector(thedo);
   }
}
