//
// menu.cpp for  in /home/hazer/cpp_arcade/SDL2
//
// Made by hazer
// Login   <hazer@epitech.net>
//
// Started on  Mon Mar 20 16:14:17 2017 hazer
// Last update Sun Apr  9 20:04:30 2017 David Munoz
//

#include "menuSdl.hpp"

Menu::Menu()
{
  int i;

  for (i = 0; i < 6; i++)
    images[i] = NULL;
  for (i = 0; i < 2; i++)
    play[i] = NULL;
  for (i = 0; i < 6; i++)
    launch[i] = NULL;
  done = 0;
  mode = -1;
  mode_game = 2;
  animation = 0;
}

Menu::~Menu()
{
  int	i;

  for (i = 0; i < 7; i++)
    SDL_FreeSurface(images[i]) , images[i] = NULL;
  for (i = 0; i < 5; i++)
    SDL_FreeSurface(launch[i]) , launch[i] = NULL;
  SDL_FreeSurface(play[0]) , play[0] = NULL;
  SDL_FreeSurface(play[1]) , play[1] = NULL;
}

int	Menu::getMode() const
{
  return (this->mode);
}

int	Menu::getModeGame() const
{
  return (this->mode_game);
}

int	Menu::getDone() const
{
  return (this->done);
}

void	Menu::setDone(int num)
{
  this->done = num;
}

void	Menu::setPos()
{
  titre.w = images[1]->w;
  titre.h = images[1]->h;
  titre.x = 225;
  titre.y = 25;

  library.w = images[2]->w;
  library.h = images[2]->h;
  library.x = 10;
  library.y = 180;

  next.w = images[3]->w-200;
  next.h = images[3]->h-50;
  next.x = 575;
  next.y = 260;

  prev.w = images[4]->w-200;
  prev.h = images[4]->h-50;
  prev.x = 400;
  prev.y = 260;

  next2.w = images[3]->w-200;
  next2.h = images[3]->h-50;
  next2.x = 575;
  next2.y = 460;

  prev2.w = images[4]->w-200;
  prev2.h = images[4]->h-50;
  prev2.x = 400;
  prev2.y = 460;

  image_game.w = images[5]->w;
  image_game.h = images[5]->h;
  image_game.x = -50;
  image_game.y = 380;

  postypej1.w = images[6]->w;
  postypej1.h = images[6]->h;
  postypej1.x = 370;
  postypej1.y = 180;

  posgame.w = play[0]->w;
  posgame.h = play[0]->h;
  posgame.x = 290;
  posgame.y = 385;

  launch_game.w = launch[0]->w;
  launch_game.h = launch[0]->h;
  launch_game.x = 250;
  launch_game.y = 500;
}

bool	Menu::check_images()
{
  int	i;

  for (i = 1; i < 7; i++)
    SDL_SetColorKey(images[i], SDL_TRUE, 0);
  for (i = 0; i < 6; i++)
    SDL_SetColorKey(launch[i], SDL_TRUE, 0);
  SDL_SetColorKey(play[0], SDL_TRUE, 0);
  SDL_SetColorKey(play[1], SDL_TRUE, 0);
  for (i = 0; i < 7; i++)
    if (images[i]==NULL)
      {
	std::cerr << "Probleme de chargement d'une des images [images]" << std::endl;
	return (false);
      }
  for (i = 0; i < 5; i++)
    if (launch[i] == NULL)
      {
	std::cerr << "Probleme de chargement d'une image typejoueur [launch]" << std::endl;
	return (false);
      }
  if (play[0] == NULL || play[1] == NULL)
    {
      std::cerr << "Probleme de chargement d'une image typejoueur [play]" << std::endl;
      return (false);
    }
  return (true);
}

void	Menu::setTexture(SDL_Renderer *pRenderer)
{
  texture[0] = SDL_CreateTextureFromSurface(pRenderer, images[0]);
  texture[1] = SDL_CreateTextureFromSurface(pRenderer, images[1]);
  texture[2] = SDL_CreateTextureFromSurface(pRenderer, images[2]);
  texture[3] = SDL_CreateTextureFromSurface(pRenderer, images[3]);
  texture[4] = SDL_CreateTextureFromSurface(pRenderer, images[4]);
  texture[5] = SDL_CreateTextureFromSurface(pRenderer, images[3]);
  texture[6] = SDL_CreateTextureFromSurface(pRenderer, images[4]);
  texture[7] = SDL_CreateTextureFromSurface(pRenderer, images[6]);
  texture[8] = SDL_CreateTextureFromSurface(pRenderer, play[0]);
  texture[9] = SDL_CreateTextureFromSurface(pRenderer, images[5]);
  texture[10] = SDL_CreateTextureFromSurface(pRenderer, launch[0]);
}

bool Menu::init(SDL_Renderer *pRenderer)
{
  images[0] = SDL_LoadBMP("./data/background.bmp");
  images[1] = SDL_LoadBMP("./data/titre.bmp");
  images[2] = SDL_LoadBMP("./data/library.bmp");
  images[3] = SDL_LoadBMP("./data/next.bmp");
  images[4] = SDL_LoadBMP("./data/prev.bmp");
  images[5] = SDL_LoadBMP("./data/game.bmp");
  images[6] = SDL_LoadBMP("./data/sdl2.bmp");

  play[0] = SDL_LoadBMP("./data/pacman.bmp");
  play[1] = SDL_LoadBMP("./data/snake.bmp");

  launch[0] = SDL_LoadBMP("./data/play_red.bmp");
  launch[1] = SDL_LoadBMP("./data/play_green.bmp");
  launch[2] = SDL_LoadBMP("./data/play_blue.bmp");
  launch[3] = SDL_LoadBMP("./data/play_pink.bmp");
  launch[4] = SDL_LoadBMP("./data/play_jaune.bmp");
  launch[5] = SDL_LoadBMP("./data/play_strange.bmp");

  setPos();
  if (check_images() == false)
    return (false);
  setTexture(pRenderer);
  return (true);
}

void	Menu::change_state(SDL_Renderer *pRenderer, int state)
{
  if (state == 0 || state == 1)
    mode = state;
  else if (state == 2 || state == 3)
    {
      mode_game == 2 ? mode_game = 3 : mode_game = 2;
      texture[8] = SDL_CreateTextureFromSurface(pRenderer, play[mode_game - 2]);
    }
}

int	Menu::clic(int x, int y, SDL_Renderer *pRenderer)
{
  if((next.x<x)&&(next.x+next.w>x)&&(next.y<y) &&(next.y+next.h>y))
    {
      mode = 1;
      return (1);
    }
  else if((prev.x<x)&&(prev.x+prev.w>x)&&(prev.y<y) && (prev.y+prev.h>y))
    {
      mode = 0;
      return (0);
    }
  else if((next2.x<x)&&(next2.x+next2.w>x)&&(next2.y<y) &&(next2.y+next2.h>y))
    change_state(pRenderer, NEXT_GAME);
  else if((prev2.x<x)&&(prev2.x+prev2.w>x)&&(prev2.y<y) && (prev2.y+prev2.h>y))
    change_state(pRenderer, PREVIOUS_GAME);
  else if((launch_game.x<x)&&(launch_game.x+launch_game.w>x)&&(launch_game.y<y) && (launch_game.y+launch_game.h>y))
    setDone(2);
  return (-1);
}

void	Menu::change_color(SDL_Renderer *pRenderer)
{
  if (animation == 5)
    animation = 0;
  else
    animation++;
  texture[10] = SDL_CreateTextureFromSurface(pRenderer, launch[animation]);
}

void	Menu::aff(SDL_Renderer *pRenderer)
{
  if (texture[0] && texture[1] && texture[2] && texture[3] && texture[4] && texture[5] && texture[6] && texture[7] && texture[8] && texture[9] && texture[10])
    {
      SDL_RenderCopy(pRenderer, texture[0], NULL, NULL);
      SDL_RenderCopy(pRenderer, texture[1], NULL, &titre);
      SDL_RenderCopy(pRenderer, texture[2], NULL, &library);
      SDL_RenderCopy(pRenderer, texture[3], NULL, &next);
      SDL_RenderCopy(pRenderer, texture[4], NULL, &prev);
      SDL_RenderCopy(pRenderer, texture[5], NULL, &next2);
      SDL_RenderCopy(pRenderer, texture[6], NULL, &prev2);
      SDL_RenderCopy(pRenderer, texture[7], NULL, &postypej1);
      SDL_RenderCopy(pRenderer, texture[8], NULL, &posgame);
      SDL_RenderCopy(pRenderer, texture[9], NULL, &image_game);
      SDL_RenderCopy(pRenderer, texture[10], NULL, &launch_game);
      SDL_RenderPresent(pRenderer);
    }
}

extern "C" int     makeMenu()
{
  SDL_Event     event;
  SDL_Window    *screen;
  SDL_Renderer  *pRenderer;
  Menu          *menu;
  int		ret;
  int		mod;
  int		gam;
  
  menu = new Menu();
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
      throw std::runtime_error(std::string("SDL_Init : ") + SDL_GetError());
      return (-1);
    }
  if ((screen = SDL_CreateWindow("Menu arcade SDL 2.0",
				 SDL_WINDOWPOS_CENTERED,
				 SDL_WINDOWPOS_CENTERED,
				 WIDTH, HEIGHT,
				 SDL_WINDOW_SHOWN)) == NULL)
    {
      throw std::runtime_error(std::string("SDL_CreateWindow : ") + SDL_GetError());
      return (-1);
    }

  if ((pRenderer = SDL_CreateRenderer(screen, -1,
				      SDL_RENDERER_ACCELERATED |
				      SDL_RENDERER_PRESENTVSYNC)) == NULL)
    {
      throw std::runtime_error(std::string("SDL_CreateRenderer : ") + SDL_GetError());
      return (-1);
    }
  if (!menu->init(pRenderer))
    return (-1);
  while (!menu->getDone())
    {
      while(SDL_PollEvent(&event))
	{
	  menu->change_color(pRenderer);
	  switch(event.type)
	    {
	    case SDL_KEYDOWN:
	      if (event.key.keysym.sym == SDLK_ESCAPE)
		menu->setDone(-1);
	      else if (event.key.keysym.sym == 233)
		{
		  menu->change_state(pRenderer, PREVIOUS_LIB);
		  menu->setDone(1);
		}
	      else if (event.key.keysym.sym == 34)
		{
		  menu->change_state(pRenderer, NEXT_LIB);
		  menu->setDone(1);
		}
	      else if (event.key.keysym.sym == 39)
		menu->change_state(pRenderer, PREVIOUS_GAME);
	      else if (event.key.keysym.sym == 40)
		menu->change_state(pRenderer, NEXT_GAME);
	      else if (event.key.keysym.sym == 45);
	      else if (event.key.keysym.sym == 232);
	      else if (event.key.keysym.sym == SDLK_RETURN)
		menu->setDone(2);
	      break;
	    case SDL_QUIT:
	      menu->setDone(1);
	      break;
	    case SDL_MOUSEBUTTONUP:
	      if ((menu->clic(event.button.x, event.button.y, pRenderer)) != -1)
		menu->setDone(1);
	      break;
	    default:
	      break;
	    }
	}
      menu->aff(pRenderer);
    }
  ret = menu->getDone();
  mod = menu->getMode();
  gam = menu->getModeGame() + 8;
  delete menu;
  SDL_DestroyRenderer(pRenderer);
  SDL_DestroyWindow(screen);
  SDL_Quit();
  if (ret == 1)
    return (mod);
  else if (ret == -1)
    return (4);
  else
    return (gam);
}
