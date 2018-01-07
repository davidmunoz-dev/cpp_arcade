//
// menu.hpp for  in /home/hazer/cpp_arcade/SDL2
//
// Made by hazer
// Login   <hazer@epitech.net>
//
// Started on  Mon Mar 20 16:28:28 2017 hazer
// Last update Fri Apr  7 15:20:58 2017 David Munoz
//

#ifndef	_MENU_HPP_
# define _MENU_HPP_

#include <SDL2/SDL.h>
#include <iostream>
#include <string>

#define WIDTH   800
#define HEIGHT  600

enum    Command
  {
    PREVIOUS_LIB = 0,
    NEXT_LIB = 1,
    PREVIOUS_GAME = 2,
    NEXT_GAME = 3,
    RESTART_GAME = 4,
    BACK_MENU = 5
  };

class	Menu;

class Menu
{
private:
  //Surfaces pour le menu
  SDL_Surface *images[7];
  SDL_Surface *play[2];
  SDL_Surface *launch[6];

  //Position et taille des boutons
  SDL_Rect library, next, prev, next2, prev2,
    titre, game, ncurses;

  //Positions et surfaces du texte des joueurs
  SDL_Rect postxtj1, postxtj2;

  //Positions et surfaces des types de jeu
  SDL_Rect	image_game, posgame;
  SDL_Rect	postypej1, postypej2;
  SDL_Rect	launch_game;
  SDL_Texture	*texture[11];
  //Mode de jeu (lib/jeu)
  int	mode;
  int	mode_game;
  int	animation;
  int	done;

public:
  Menu();
  ~Menu();

  int	getDone() const;
  void	setDone(int);
  int	getMode() const;
  int	getModeGame() const;
  bool	init(SDL_Renderer *pRenderer);
  void	change_state(SDL_Renderer *pRenderer, int state);
  void	setPos();
  void	setTexture(SDL_Renderer *pRenderer);
  bool	check_images();
  void	change_color(SDL_Renderer *pRenderer);
  int	clic(int x, int y, SDL_Renderer *pRenderer);
  void	aff(SDL_Renderer *pRenderer);
};

#endif /* _MENU_HPP_ */
