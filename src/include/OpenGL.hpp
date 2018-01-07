//
// OpenGL.hpp for OpenGl in /Users/adrienmissioux/Documents/Epitech/cpp_arcade/
//
// Made by Adrien Missioux
// Login   <adrien.missioux@epitech.eu@epitech.eu>
//
// Started on  Sat Mar 18 10:28:36 2017 Adrien Missioux
// Last update Sat Mar 18 10:31:04 2017 Adrien Missioux
//

#ifndef _OPENGL_HPP_
#define _OPENGL_HPP_

#include "ALib.hpp"

class OpenGL : public ALib {
public:
  OpenGL(const std::string & path);
  virtual void *init();
};

#endif
