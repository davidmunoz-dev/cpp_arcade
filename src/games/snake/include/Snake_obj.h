/*
** Snake.h for  in /home/munoz_d/Desktop/snake/include
** 
** Made by David Munoz
** Login   <david.munoz@epitech.eu>
** 
** Started on  Fri Mar 31 13:54:54 2017 David Munoz
** Last update Sun Apr  9 19:29:28 2017 David Munoz
*/

#ifndef _SNAKE_OBJ_H_
#define _SNAKE_OBJ_H_

#include "Position.h"
#include <deque>

enum	Direction
  {
    GO_UP = 2,
    GO_DOWN = 3,
    GO_LEFT = 4,
    GO_RIGHT = 5
  };

enum	Key
  {
    GO_FORWARD = 6,
    PREVIOUS_LIB = 7,
    NEXT_LIB = 8,
    PREVIOUS_GAME = 9,
    NEXT_GAME = 10,
    RESTART_GAME = 11,
    BACK_MENU = 12
  };

typedef struct	s_rect
{
  int	x;
  int	y;
  int	w;
  int	h;
}		t_rect;

class Snake_obj : public Position
{
 public:
  Snake_obj();
  ~Snake_obj();
  void		grow();
  void		move();
  void		set_collision_state( bool state );
  bool		get_collision_state() const;
  bool		self_collide();
  int		get_frontX() const;
  int		get_frontY() const;
  int		get_posX(int pos) const;
  int		get_posY(int pos) const;
  void		set_body_rect(int x, int y);
  Direction	get_direction() const;
  
  void		go_right();
  void		go_left();
  void		go_up();
  void		go_down();
  void		set_direction(Direction value);
  t_rect*	get_body_ptr();
  int		length() const;

  void		set_score(std::string);
  std::string	get_score();
  
 private:
  std::deque<t_coord> snakePos;
  t_rect	body;
  Direction	direction;
  Key		key;	
  bool		collided;
  void		move_to_direction();
};

#endif /* _SNAKE_OBJ_H_ */
