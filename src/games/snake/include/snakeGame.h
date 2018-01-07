/*
** Game.h for  in /home/munoz_d/Desktop/snake/include
**
** Made by David Munoz
** Login   <david.munoz@epitech.eu>
**
** Started on  Fri Mar 31 13:52:36 2017 David Munoz
** Last update Sun Apr  9 19:30:43 2017 David Munoz
*/

#ifndef _SNAKEGAME_H_
#define _SNAKEGAME_H_

#include <string>
#include <cstdlib>
#include "../../../games/IAllGames.hpp"
#include "../../../include/ALib.hpp"
#include "Map.h"
#include "Snake_obj.h"
#include "Food_obj.h"
#include "libGra.h"

#define WIDTH		674
#define HEIGHT		660
#define IMAGE_WIDTH	30
#define IMAGE_HEIGHT	30
#define SNAKE		254
#define APPLE	        253
#define DELAY		125
#define	SNAKE_OK	0
#define	SNAKE_ERR	1

extern int x;
extern int y;

class snakeGame : public IAllGames
{
 public:
  snakeGame();
  ~snakeGame();

  void	collision(Map map);
  void	collision_right();
  void	collision_left();
  void	collision_up();
  void	collision_down();

  Snake_obj	getSnake() const;
  void		setSnake(Snake_obj _snake);
  Food_obj	getFood() const;
  void		setFood(Food_obj _food);
  
  void          set_score(std::string);
  std::string   get_score() const;

  
  void	selector(arcade::CommandType);
  void	getWhereAmI();
  void	getMap() const;
  void	goUp();
  void	goDown();
  void	goLeft();
  void	goRight();
  void	goForward();
  void	shoot();
  void	illegal();
  void	play();
  uint16_t	getPosX() const;
  uint16_t	getPosY() const;
  libGra	getlibGra() const;

 protected:
  libGra	*func;
  std::vector<std::string> initMap;
 private:
  std::string str_score;
  Snake_obj	snake;
  Food_obj	food;
};

#endif /*    _SNAKEGAME_H_	*/
