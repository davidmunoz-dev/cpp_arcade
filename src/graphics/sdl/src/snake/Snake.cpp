//
// Snake.cpp for  in /home/munoz_d/Desktop/snake/src
// 
// Made by David Munoz
// Login   <david.munoz@epitech.eu>
// 
// Started on  Fri Mar 31 13:50:41 2017 David Munoz
// Last update Sun Apr  9 18:23:36 2017 David Munoz
//

#include "Snake.h"
#include "Game.h"

Snake::Snake()
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

Snake::~Snake()
{}

//Grow the snake
void	Snake::grow()
{
  move_to_direction();
  snakePos.push_front(pos);
}

//Move the snake
void	Snake::move()
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

// Move the head of the snake
void	Snake::move_to_direction()
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

//head position X of the snake
int	Snake::get_frontX() const
{
  return (snakePos.front().x);
}

//head position Y of the snake
int	Snake::get_frontY() const
{
  return (snakePos.front().y);
}

//Size of the sake
int	Snake::length() const
{
  return (snakePos.size());
}

int	Snake::get_posX(int pos) const
{
  return (snakePos[pos].x);
}

int	Snake::get_posY(int pos) const
{
  return (snakePos[pos].y);
}

void	Snake::set_body_rect(int x, int y)
{
  body.x = x;
  body.y = y;
}

t_rect*	Snake::get_body_ptr()
{
  return (&body);
}

bool	Snake::self_collide() const
{
  unsigned int	i;

  for (i = 1; i < snakePos.size(); ++i)
    {
      if ((snakePos.front().x == snakePos[i].x) &&
	  (snakePos.front().y == snakePos[i].y))
	return (true);
    }
  return (false);
}

Direction	Snake::get_direction() const
{
  return (direction);
}

int	Snake::go_right()
{
  direction = GO_RIGHT;
  return (GO_RIGHT);
}

int	Snake::go_left()
{
  direction = GO_LEFT;
  return (GO_LEFT);
}

int	Snake::go_up()
{
  direction = GO_UP;
  return (GO_UP);
}

int	Snake::go_down()
{
  direction = GO_DOWN;
  return (GO_DOWN);
}
