/*
** LTexture.h for  in /home/munoz_d/Desktop/snake/include
** 
** Made by David Munoz
** Login   <david.munoz@epitech.eu>
** 
** Started on  Fri Mar 31 13:47:50 2017 David Munoz
** Last update Wed Apr  5 19:38:39 2017 David Munoz
*/

#ifndef _LTEXTURE_H_
#define _LTEXTURE_H_

#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_image.h"
#include <fstream>
#include <cstdlib>

class LTexture
{
 public:
  LTexture();
  ~LTexture();
  bool loadFromFile(std::string path, SDL_Renderer* renderer);
  bool loadFromRenderedText(std::string textTexture, SDL_Color textColor, TTF_Font* mFont, SDL_Renderer* renderer);
  void	renderTexture(int x, int y, SDL_Renderer* renderer);
  int	getWidth() const;
  int	getHeight() const;

 private:
  SDL_Texture	*mTexture;
  int		mWidth;
  int		mHeight;
};

#endif /* _LTEXTURE_H_ */
