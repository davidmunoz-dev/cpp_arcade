/*
** GL_Utils.h for GL_Utils in /home/lucas/rendu/C++/cpp_arcade/GL/src
** 
** Made by Lucas
** Login   <lucas.onillon@epitech.eu>
** 
** Started on  Sat Mar 25 22:40:03 2017 Lucas
// Last update Mon Mar 27 07:27:51 2017 Lucas
*/

#ifndef GLUTILS_H_
# define GLUTILS_H_

# include "GL_Load.h"
# include <stdio.h>

/*
** Screen parameters.
*/
const int		SCREEN_WIDTH = 1080;
const int		SCREEN_HEIGHT = 720;
const int		SCREEN_FPS = 60;

/*
** Macro definitions.
*/
# define MOVE_CENTER	glTranslatef( SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f, 0.f );

/*
** Global definitions.
*/
extern int			MenuStatus;

/*
** Viewport mode -> Handle the game scene (menu, snake, pacman).
*/
enum			ViewPortMode
{
			VIEWPORT_MODE_MENU,
			VIEWPORT_MODE_GAME1,
			VIEWPORT_MODE_GAME2,
			NONE
};

/*
** Function prototypes.
*/
bool			initGL();
void			runMainLoop(int val);
void			handleKeys(unsigned char key, int x, int y);
void			update();
void			render();

#endif
