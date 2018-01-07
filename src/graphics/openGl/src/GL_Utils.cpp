//
// GL_Utils.cpp for GL_utils in /home/lucas/rendu/C++/cpp_arcade/GL/src
// 
// Made by Lucas
// Login   <lucas.onillon@epitech.eu>
// 
// Started on  Sat Mar 25 22:43:51 2017 Lucas
// Last update Sat Apr  1 15:26:50 2017 Lucas
//

#include "GL_Utils.hpp"

int gViewportMode = VIEWPORT_MODE_MENU;

bool		initGL()
{
  GLenum GL_error;

  glViewport( 0.f, 0.f, SCREEN_WIDTH, SCREEN_HEIGHT );
  //Initialize Projection Matrix
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();
  glOrtho( 0.0, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0, 1.0, -1.0 );
  //Initialize Modelview Matrix
  glMatrixMode( GL_MODELVIEW );
  glLoadIdentity();
  glClearColor( 0.f, 0.f, 0.f, 1.f );
  GL_error = glGetError();
  if (GL_error != GL_NO_ERROR)
    {
      std::cerr << "Error initializing OpenGL! : " << gluErrorString(GL_error) << std::endl;
      return false;
    }
  return true;
}

void update()
{

}

void render()
{
    glClear( GL_COLOR_BUFFER_BIT );

    //Reset modelview matrix
    glLoadIdentity();
    MOVE_CENTER;
    if (gViewportMode == VIEWPORT_MODE_MENU)
      {
	//Arcade - Top title
	glViewport( SCREEN_WIDTH / 4.f, SCREEN_HEIGHT / 1.5f, SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 3.f );
	glBegin( GL_QUADS );
	  glColor3f( 0.5f, 0.f, 1.f );
	  glVertex2f( -SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f );
	  glVertex2f(  SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f );
	  glVertex2f(  SCREEN_WIDTH / 4.f,  SCREEN_HEIGHT / 4.f );
	  glVertex2f( -SCREEN_WIDTH / 4.f,  SCREEN_HEIGHT / 4.f );
	glEnd();

	//Choose Library - Middle left container
	glViewport( 0.f, SCREEN_HEIGHT / 3.f, SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 3.f );
	glBegin( GL_QUADS );
	  glColor3f( 0.f, 0.f, 1.f );
	  glVertex2f( -SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f );
	  glVertex2f(  SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f );
	  glVertex2f(  SCREEN_WIDTH / 4.f,  SCREEN_HEIGHT / 4.f );
	  glVertex2f( -SCREEN_WIDTH / 4.f,  SCREEN_HEIGHT / 4.f );
	glEnd();


	//Library choices - Middle right container
	glViewport( SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 3.f, SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 3.f );
	glBegin( GL_QUADS );
	  glColor3f( 1.f, 1.f, 0.f );
	  glVertex2f( -SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f );
	  glVertex2f(  SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f );
	  glVertex2f(  SCREEN_WIDTH / 4.f,  SCREEN_HEIGHT / 4.f );
	  glVertex2f( -SCREEN_WIDTH / 4.f,  SCREEN_HEIGHT / 4.f );
	glEnd();

	//Choose game - Bottom left container
	glViewport( 0.f, 0.f, SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 3.f );
	glBegin( GL_QUADS );
	  glColor3f( 1.f, 0.f, 0.f );
	  glVertex2f( -SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f );
	  glVertex2f(  SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f );
	  glVertex2f(  SCREEN_WIDTH / 4.f,  SCREEN_HEIGHT / 4.f );
	  glVertex2f( -SCREEN_WIDTH / 4.f,  SCREEN_HEIGHT / 4.f );
	glEnd();

	//Game choices - Bottom right container
	glViewport( SCREEN_WIDTH / 2.f, 0.f, SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 3.f );
	glBegin( GL_QUADS );
	  glColor3f( 0.f, 1.f, 0.f );
	  glVertex2f( -SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f );
	  glVertex2f(  SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f );
	  glVertex2f(  SCREEN_WIDTH / 4.f,  SCREEN_HEIGHT / 4.f );
	  glVertex2f( -SCREEN_WIDTH / 4.f,  SCREEN_HEIGHT / 4.f );
	  glEnd();
      }
    
    else if (gViewportMode == VIEWPORT_MODE_GAME1)
      {
	//Full size quad
	glViewport( 0.f, 0.f, SCREEN_WIDTH, SCREEN_HEIGHT );
	glBegin( GL_QUADS );
	  glColor3f( 1.f, 1.f, 1.f );
	  glVertex2f( -SCREEN_WIDTH / 8.f, -SCREEN_HEIGHT / 8.f );
	  glVertex2f(  SCREEN_WIDTH / 8.f, -SCREEN_HEIGHT / 8.f );
	  glVertex2f(  SCREEN_WIDTH / 8.f,  SCREEN_HEIGHT / 8.f );
	  glVertex2f( -SCREEN_WIDTH / 8.f,  SCREEN_HEIGHT / 8.f );
	  glColor3f( 0.f, 0.f, 0.f );
	  glVertex2f( -SCREEN_WIDTH / 16.f, -SCREEN_HEIGHT / 16.f );
	  glVertex2f(  SCREEN_WIDTH / 16.f, -SCREEN_HEIGHT / 16.f );
	  glVertex2f(  SCREEN_WIDTH / 16.f,  SCREEN_HEIGHT / 16.f );
	  glVertex2f( -SCREEN_WIDTH / 16.f,  SCREEN_HEIGHT / 16.f );
	glEnd();
	
	//Radar quad
	glViewport( SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f, SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f );
	glBegin( GL_QUADS );
	glColor3f( 1.f, 1.f, 1.f );
	glVertex2f( -SCREEN_WIDTH / 8.f, -SCREEN_HEIGHT / 8.f );
	glVertex2f(  SCREEN_WIDTH / 8.f, -SCREEN_HEIGHT / 8.f );
	glVertex2f(  SCREEN_WIDTH / 8.f,  SCREEN_HEIGHT / 8.f );
	glVertex2f( -SCREEN_WIDTH / 8.f,  SCREEN_HEIGHT / 8.f );
	glColor3f( 0.f, 0.f, 0.f );
	glVertex2f( -SCREEN_WIDTH / 16.f, -SCREEN_HEIGHT / 16.f );
	glVertex2f(  SCREEN_WIDTH / 16.f, -SCREEN_HEIGHT / 16.f );
	glVertex2f(  SCREEN_WIDTH / 16.f,  SCREEN_HEIGHT / 16.f );
	glVertex2f( -SCREEN_WIDTH / 16.f,  SCREEN_HEIGHT / 16.f );
	glEnd();
      }
    else if (gViewportMode == VIEWPORT_MODE_GAME2)
      {
	//Full size quad
	glViewport( 0.f, 0.f, SCREEN_WIDTH, SCREEN_HEIGHT );
	glBegin( GL_QUADS );
	  glColor3f( 1.f, 0.f, 0.f );
	  glVertex2f( -SCREEN_WIDTH / 8.f, -SCREEN_HEIGHT / 8.f );
	  glVertex2f(  SCREEN_WIDTH / 8.f, -SCREEN_HEIGHT / 8.f );
	  glVertex2f(  SCREEN_WIDTH / 8.f,  SCREEN_HEIGHT / 8.f );
	  glVertex2f( -SCREEN_WIDTH / 8.f,  SCREEN_HEIGHT / 8.f );
	  glColor3f( 0.f, 0.f, 0.f );
	  glVertex2f( -SCREEN_WIDTH / 16.f, -SCREEN_HEIGHT / 16.f );
	  glVertex2f(  SCREEN_WIDTH / 16.f, -SCREEN_HEIGHT / 16.f );
	  glVertex2f(  SCREEN_WIDTH / 16.f,  SCREEN_HEIGHT / 16.f );
	  glVertex2f( -SCREEN_WIDTH / 16.f,  SCREEN_HEIGHT / 16.f );
	glEnd();

	//Radar quad
	glViewport( SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f, SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f );
	glBegin( GL_QUADS );
	  glColor3f( 1.f, 0.f, 0.f );
	  glVertex2f( -SCREEN_WIDTH / 8.f, -SCREEN_HEIGHT / 8.f );
	  glVertex2f(  SCREEN_WIDTH / 8.f, -SCREEN_HEIGHT / 8.f );
	  glVertex2f(  SCREEN_WIDTH / 8.f,  SCREEN_HEIGHT / 8.f );
	  glVertex2f( -SCREEN_WIDTH / 8.f,  SCREEN_HEIGHT / 8.f );
	  glColor3f( 0.f, 0.f, 0.f );
	  glVertex2f( -SCREEN_WIDTH / 16.f, -SCREEN_HEIGHT / 16.f );
	  glVertex2f(  SCREEN_WIDTH / 16.f, -SCREEN_HEIGHT / 16.f );
	  glVertex2f(  SCREEN_WIDTH / 16.f,  SCREEN_HEIGHT / 16.f );
	  glVertex2f( -SCREEN_WIDTH / 16.f,  SCREEN_HEIGHT / 16.f );
	glEnd();
      }
    glutSwapBuffers();
}

void handleKeys( unsigned char key, int x, int y )
{
  (void)x;
  (void)y;
  switch (key)
    {
    case 'a':
      {
	gViewportMode++;
	if( gViewportMode > VIEWPORT_MODE_GAME2)
	  {
	    gViewportMode = VIEWPORT_MODE_MENU;
	  }
	break;
      }
    case '2':
      {
	MenuStatus = 0;
	break;
      }
    case '3':
      {
	MenuStatus = 1;
	break;
      }
    case '4':
      {
	MenuStatus = 2;
	break;
      }
    case '5':
      {
	MenuStatus = 3;
	break;
      }
    case '8':
      {
	MenuStatus = 4;
	break;
      }
    case '9':
      {
	MenuStatus = 5;
	break;
      }
    case 27:
      {
	MenuStatus = -1;
	break;
      }
    }
}
