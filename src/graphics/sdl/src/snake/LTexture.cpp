//
// LTexture.cpp for  in /home/munoz_d/Desktop/snake/src
// 
// Made by David Munoz
// Login   <david.munoz@epitech.eu>
// 
// Started on  Fri Mar 31 13:49:23 2017 David Munoz
// Last update Sun Apr  9 13:53:58 2017 David Munoz
//

#include "LTexture.h"
#include <iostream>

LTexture::LTexture()
{
  mTexture = 0;
  mHeight  = 0;
  mWidth = 0;
}

LTexture::~LTexture()
{}

// Load an image
bool LTexture::loadFromFile(std::string path, SDL_Renderer* renderer)
{
  SDL_Texture* newTexture = NULL;
  SDL_Surface* loadedSurface;

  if ((loadedSurface = IMG_Load(path.c_str())) == NULL)
    {
      throw std::runtime_error(std::string("IMG_Load : ") + SDL_GetError());
      return (NULL);
    }
  if ((newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface)) == NULL)
    {
      throw std::runtime_error(std::string("SDL_CreateTextureFromSurface : ") + SDL_GetError());
      return (NULL);
    }
  mWidth  = loadedSurface->w;
  mHeight = loadedSurface->h;
  SDL_FreeSurface(loadedSurface);
  mTexture = newTexture;
  return (mTexture);
}

//Load a text
bool	LTexture::loadFromRenderedText(std::string textTexture, SDL_Color textColor,
				       TTF_Font* mFont, SDL_Renderer* renderer)
{
  SDL_Surface* textSurface;  

  if ((textSurface = TTF_RenderText_Solid(mFont, textTexture.c_str(), textColor)) == NULL)
    {
      throw std::runtime_error(std::string("TTF_RenderText_Solid : ") + SDL_GetError());
      return (NULL);
    }
  else
    {
      if ((mTexture = SDL_CreateTextureFromSurface(renderer, textSurface)) == NULL)
	{
	  throw std::runtime_error(std::string("SDL_CreateTextureFromSurface : ") + SDL_GetError());
	  return (NULL);
	}
      else
	{
	  mWidth  = textSurface->w;
	  mHeight = textSurface->h;
	} 
      SDL_FreeSurface(textSurface);;
    }
  return (mTexture);
}

void	LTexture::renderTexture(int x, int y, SDL_Renderer *renderer)
{
  SDL_Rect renderQuad = {x, y, mWidth, mHeight};

  SDL_RenderCopy(renderer, mTexture, NULL, &renderQuad);
}

int	LTexture::getWidth() const
{
  return (this->mWidth);
}

int	LTexture::getHeight() const
{
  return (this->mHeight);
}
