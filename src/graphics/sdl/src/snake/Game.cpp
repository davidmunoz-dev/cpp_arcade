//
// Game.cpp for  in /home/munoz_d/Desktop/snake/src
//
// Made by David Munoz
// Login   <david.munoz@epitech.eu>
//
// Started on  Fri Mar 31 13:48:52 2017 David Munoz
// Last update Sun Apr  9 22:46:20 2017 Adrien Missioux
//

#include "Game.h"
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <unistd.h>

Game::Game()
{
  textColor.r = 255;
  textColor.g = 255;
  textColor.b = 255;
  textColor.a = 0;
  str_score = "0";
}

Game::~Game()
{
  TTF_CloseFont(font);
  TTF_Quit();
  SDL_DestroyRenderer(pRenderer);
  SDL_DestroyWindow(screen);
  IMG_Quit();
  SDL_Quit();
}

//	Load all the textures
int	Game::loadTexture()
{
  if ((font = TTF_OpenFont("./fonts/pixeled.ttf", 25)) == NULL)
    {
      throw std::runtime_error(std::string("TFF_OpenFont : ") + SDL_GetError());
      return (SNAKE_ERR);
    }
  if (!textTexture_1.loadFromRenderedText("Score", textColor, font, pRenderer)
      || !textTexture_2.loadFromRenderedText("END OF GAME", textColor, font, pRenderer)
      || !textTexture_3.loadFromRenderedText("Escape for exit", textColor, font, pRenderer)
      ||!textTexture_4.loadFromRenderedText( "SNAKE", textColor, font, pRenderer))
    {
      throw std::runtime_error(std::string("textTexture.loadFromRenderedText : ") + SDL_GetError());
      return (SNAKE_ERR);
    }
  if (!scoreTexture.loadFromRenderedText("0", textColor, font, pRenderer))
    {
      throw std::runtime_error(std::string("TTF_Init : ") + SDL_GetError());
      return (SNAKE_ERR);
    }
  if (!food_texture.loadFromFile("./images/apple.png", pRenderer)
      || !wall.loadFromFile("./images/brick.png", pRenderer)
      || !background.loadFromFile("./images/background.png", pRenderer))
    {
      throw std::runtime_error(std::string("Food/Wall.texture.loadFromFile : ") + SDL_GetError());
      return (SNAKE_ERR);
    }
  return (SNAKE_OK);
}

extern "C" int	initLib()
{
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
      throw std::runtime_error(std::string("SDL_Init : ") + SDL_GetError());
      return (SNAKE_ERR);
    }
  if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear"))
    {
      throw std::runtime_error(std::string("SDL_SetHint : ") + SDL_GetError());
      return (SNAKE_ERR);
    }
  if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
    {
      throw std::runtime_error(std::string("IMG_Init : ") + SDL_GetError());
      return (SNAKE_ERR);
    }
  if (TTF_Init() == -1)
    {
      throw std::runtime_error(std::string("TTF_Init : ") + SDL_GetError());
      return (SNAKE_ERR);
    }
  return (SNAKE_OK);
}

extern "C" int	closeLib()
{
  TTF_Quit();
  IMG_Quit();
  SDL_Quit();
  return (0);
}

extern "C" int	getEvent()
{
  SDL_Event	event;

  while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_KEYDOWN)
        {
	  switch(event.key.keysym.sym)
            {
	    case SDLK_LEFT:
	      return (GO_LEFT);
	    case SDLK_RIGHT:
	      return (GO_RIGHT);
	    case SDLK_UP:
	      return (GO_UP);
	    case SDLK_DOWN:
	      return (GO_DOWN);
	    case SDLK_ESCAPE:
	      return (0);
	    case 233:			// Touche 2
	      return (PREVIOUS_LIB);
	    case 34:			// Touche 3
	      return (NEXT_LIB);
	    case 40:			// Touche 4
	      return (NEXT_GAME);
	    case 39:			// Touche 5
	      return (PREVIOUS_GAME);
	    case '_':			// Touche 8
	      return (RESTART_GAME);
	    case 231:			// Touche 9
	      return (BACK_MENU);
	    default:
	      break;
            }
	}
      else if (event.type == SDL_QUIT)
	return (SNAKE_OK);
    }
  return (GO_FORWARD);
}
