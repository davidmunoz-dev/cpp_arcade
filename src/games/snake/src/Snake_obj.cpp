//
// Snake.cpp for  in /home/munoz_d/Desktop/snake/src
// 
// Made by David Munoz
// Login   <david.munoz@epitech.eu>
// 
// Started on  Fri Mar 31 13:50:41 2017 David Munoz
// Last update Sun Apr  9 14:39:09 2017 David Munoz
//

#include "Snake_obj.h"
#include "snakeGame.h"

Snake_obj::Snake_obj()
{
  pos.x = COL_SIZE / 2;
  pos.y = ROW_SIZE / 2;

  body.x = 0;
  body.y = 0;
  body.w = IMAGE_WIDTH;
  body.h = IMAGE_HEIGHT;

  snakePos.push_front(pos);
  direction = GO_RIGHT;
  collided = false;
}

Snake_obj::~Snake_obj()
{}

//Grow the snake
void	Snake_obj::grow()
{
  move_to_direction();
  snakePos.push_front(pos);
}

void	Snake_obj::move()
{
  int	i;

  for (i = snakePos.size() - 1; i > 0; --i)
    {
      snakePos[i].x = snakePos[i-1].x;
      snakePos[i].y = snakePos[i-1].y;
    }
  move_to_direction();
  snakePos.front() = pos;
}

void	Snake_obj::move_to_direction()
{
  pos = snakePos.front();

  switch (direction)
    {
    case GO_RIGHT:
      pos.x++;
      break;
    case GO_LEFT:
      pos.x--;
      break;
    case GO_UP:
      pos.y--;
      break;
    case GO_DOWN:
      pos.y++;
      break;
    }
}

void	Snake_obj::set_collision_state(bool state)
{
  collided = state;
}

bool	Snake_obj::get_collision_state() const
{
  return (collided);
}

//head position X of the snake
int	Snake_obj::get_frontX() const
{
  return (snakePos.front().x);
}

//head position Y of the snake
int	Snake_obj::get_frontY() const
{
  return (snakePos.front().y);
}

//Size of the sake
int	Snake_obj::length() const
{
  return (snakePos.size());
}

int	Snake_obj::get_posX(int pos) const
{
  return (snakePos[pos].x);
}

int	Snake_obj::get_posY(int pos) const
{
  return (snakePos[pos].y);
}

void	Snake_obj::set_body_rect(int x, int y)
{
  body.x = x;
  body.y = y;
}

t_rect*	Snake_obj::get_body_ptr()
{
  return (&body);
}

bool	Snake_obj::self_collide()
{
  unsigned int	i;

  for (i = 1; i < snakePos.size(); ++i)
    {
      if ((snakePos.front().x == snakePos[i].x) &&
	  (snakePos.front().y == snakePos[i].y))
	{
	  set_collision_state(true);
	  return (true);
	}
    }
  return (false);
}

Direction	Snake_obj::get_direction() const
{
  return (this->direction);
}

void	Snake_obj::go_right()
{
  this->direction = GO_RIGHT;
}

void	Snake_obj::go_left()
{
  this->direction = GO_LEFT;
}

void	Snake_obj::go_up()
{
  this->direction = GO_UP;
}

void	Snake_obj::go_down()
{
  this->direction = GO_DOWN;
}
