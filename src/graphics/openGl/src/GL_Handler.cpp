//
// main.cpp for main in /home/lucas/rendu/C++/cpp_arcade/GL/src
// 
// Made by Lucas
// Login   <lucas.onillon@epitech.eu>
// 
// Started on  Sat Mar 25 22:35:31 2017 Lucas
// Last update Sat Apr  1 15:08:08 2017 Lucas
//

#include "GL_Utils.hpp"

int MenuStatus;

void		runMainLoop(int val)
{
  update();
  render();
  glutTimerFunc(1000 / SCREEN_FPS, runMainLoop, val);
  if (MenuStatus != -1)
    glutLeaveMainLoop();
}

extern "C" int		HandleMenu()
{
  int			ac;
  char			**av;

  av = NULL;
  glutInit(&ac, av);
  glutInitContextVersion(2, 1);
  glutInitDisplayMode(GLUT_DOUBLE);
  glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
  glutCreateWindow("Arcade - OpenGL");
  MenuStatus = -1;
  if (!initGL())
    {
      std::cerr << "Unable to initialize graphics library!" << std::endl;
      return 1;
    }
  glutKeyboardFunc(handleKeys);
  glutDisplayFunc(render);
  glutTimerFunc( 1000 / SCREEN_FPS, runMainLoop, 0 );
  glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
  glutMainLoop();
  return MenuStatus;
}

extern "C" int	makeMenu()
{
  HandleMenu();
  return (MenuStatus);
}
