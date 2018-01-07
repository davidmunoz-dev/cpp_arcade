/*
** Game.h for  in /home/munoz_d/Desktop/snake/include
**
** Made by David Munoz
** Login   <david.munoz@epitech.eu>
**
** Started on  Fri Mar 31 13:52:36 2017 David Munoz
** Last update Sun Apr  9 19:12:24 2017 David Munoz
*/

#ifndef _GAME_H_
#define _GAME_H_

#include <string>
#include <cstdlib>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
#include "../../../games/IAllGames.hpp"
#include "../../../include/ALib.hpp"
#include "LTexture.h"
#include "Snake.h"
#include "Food.h"

#define WIDTH		674
#define HEIGHT		660
#define IMAGE_WIDTH	30
#define IMAGE_HEIGHT	30
#define SNAKE		254
#define APPLE	        253
#define DELAY		125
#define	SNAKE_OK	0
#define	SNAKE_ERR	1
#define	ROW_SIZE	15
#define	COL_SIZE	20

class Game
{
 public:
  Game();
  ~Game();
  int	loadTexture();

  int	rendu(int, int, int, int, bool, std::string);
  void	render_wall();
  void	render_background();
  void	render_apple(int, int);
  void	render_snake(int, int);
  void	render_eog();
  void	render_score();
  void	render_text();
  void	set_score(std::string score);
  std::string	get_score() const;

 private:
  std::string str_score;

  SDL_Window*	screen;
  SDL_Renderer*	pRenderer;
  TTF_Font*	font;

  SDL_Color	textColor;

  SDL_Rect	back_game;

  LTexture	food_texture;
  LTexture	wall;
  LTexture	background;
  LTexture	textTexture_1;
  LTexture	textTexture_2;
  LTexture	textTexture_3;
  LTexture	textTexture_4;
  LTexture	scoreTexture;

  Snake	snake;
  Food	food;
};

#endif /*    _GAME_H_	*/
