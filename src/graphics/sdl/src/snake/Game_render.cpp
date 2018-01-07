//
// Game_render.cpp for  in /home/munoz_d/Desktop/snake/src
// 
// Made by David Munoz
// Login   <david.munoz@epitech.eu>
// 
// Started on  Fri Mar 31 13:49:09 2017 David Munoz
// Last update Sun Apr  9 19:17:25 2017 David Munoz
//

#include "Game.h"
#include <unistd.h>

std::string	Game::get_score() const
{
  return (this->str_score);
}

void		Game::set_score(std::string _score)
{
  this->str_score = _score;
}

void	Game::render_background()
{
  background.renderTexture(0, 0, pRenderer);
}

//rendu du mur noir
void	Game::render_wall()
{
  int   i;
  int   j;

  // Rendu du mur haut
  for (j = 0; j < COL_SIZE + 2; ++j)
    wall.renderTexture(j * wall.getWidth() + 10, 75, pRenderer);
  // Render des murs sur le coté                   
  for (i = 0; i < ROW_SIZE; ++i )
    {
      wall.renderTexture(10, i * wall.getHeight() + IMAGE_HEIGHT + 75, pRenderer);
      wall.renderTexture(COL_SIZE * wall.getWidth() + IMAGE_WIDTH + 10, i *
                  wall.getHeight() + IMAGE_HEIGHT + 75, pRenderer);
    }
  //  Rendu du mur du bas 
  for (j = 0; j < COL_SIZE + 2; ++j)
    wall.renderTexture(j * wall.getWidth() + 10,
                 ROW_SIZE * wall.getHeight() + IMAGE_HEIGHT + 75,
                 pRenderer);
}

void	Game::render_apple(int posXfood, int posYfood)
{
  food_texture.renderTexture(posXfood * IMAGE_WIDTH + IMAGE_WIDTH + 10,
  			     posYfood * IMAGE_HEIGHT + IMAGE_HEIGHT + 75,
  			     pRenderer);
}

void	Game::render_snake(int posXsnake, int posYsnake)
{
  SDL_Rect	*sdl_rect;
  int		i;

  if ((sdl_rect = (SDL_Rect*)malloc(sizeof(SDL_Rect))) == NULL)
    exit(1);
  for (i = 0; i < snake.length(); ++i)
    {
      snake.set_body_rect(posXsnake * IMAGE_WIDTH + IMAGE_WIDTH + 10,
                          posYsnake * IMAGE_HEIGHT + IMAGE_HEIGHT + 75);
      SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
      sdl_rect->x = snake.get_body_ptr()->x;
      sdl_rect->y = snake.get_body_ptr()->y;
      sdl_rect->h = snake.get_body_ptr()->h;
      sdl_rect->w = snake.get_body_ptr()->w;
      SDL_RenderFillRect(pRenderer, sdl_rect);
    }
}

//Render end_of_game
void	Game::render_eog()
{
  textTexture_2.renderTexture(230, 300, pRenderer);
  textTexture_3.renderTexture(150, 600, pRenderer);
}

//rendu score
void	Game::render_score()
{
  scoreTexture.loadFromRenderedText(get_score().c_str(),
                                    textColor,
                                    font,
                                    pRenderer);
  scoreTexture.renderTexture(550, 2, pRenderer);
}

//rendu text
void	Game::render_text()
{
  textTexture_1.renderTexture(350, 2, pRenderer);
  textTexture_4.renderTexture(100, 2, pRenderer);
}

//      RENDER ALL the textures
int	Game::rendu(int posXsnake, int posYsnake, int posXfood, int posYfood, bool collision,
		    std::string score)
{
  static	int i = 0;

  if (i == 0)
    {
      if ((screen = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN )) == NULL)
	{
	  throw std::runtime_error(std::string("SDL_CreateWindow : ") + SDL_GetError());
	  return (SNAKE_ERR);
	}
      if ((pRenderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_ACCELERATED)) == NULL)
	{
	  throw std::runtime_error(std::string("SDL_CreateRenderer : ") + SDL_GetError());
	  return (SNAKE_ERR);
	}
      SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
      if (loadTexture() == SNAKE_ERR)
	return (SNAKE_ERR);
      i = 1;
    }
  else
    {
      SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
      SDL_RenderClear(pRenderer);
      set_score(score);
      render_background();
      render_wall();
      render_apple(posXfood, posYfood);
      render_snake(posXsnake, posYsnake);
      render_text();
      render_score();
      if (collision == true)
	render_eog();
      SDL_RenderPresent(pRenderer);
      SDL_Delay(DELAY);
    }
  return (0);
}

extern "C" int	render(int posXsnake, int posYsnake, int posXfood, int posYfood, bool collision, std::string score)
{
  static Game *game = new Game();
  
  return (game->rendu(posXsnake, posYsnake, posXfood, posYfood, collision, score));
}
