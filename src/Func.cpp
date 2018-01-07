//
// Func.cpp for Func in /Users/adrienmissioux/Documents/Epitech/cpp_arcade/src/
//
// Made by Adrien Missioux
// Login   <adrien.missioux@epitech.eu@epitech.eu>
//
// Started on  Sat Apr  1 16:52:19 2017 Adrien Missioux
// Last update Sat Apr  1 17:03:59 2017 Adrien Missioux
//

#include "Func.hpp"

Func::Func(const ALib & ala) {
  this->_actual._path = ala->_path;
  this->_actual._allLib = ala->_allLib;
  this->_actual._numLib = ala->_numLib;
  if (this->_actual._handle)
    dlclose(this->_actual._handle);
  this->_actual._handle = ala->_handle;
}

Func::~Func() {}

void Func::init() {
  // typedef int (*hello_t)();
  // hello_t makeMenu = (hello_t) this->_actual.sym("makeMenu");
  // pd = makeMenu();
}
