//
// ALib.hpp for ALib in /Users/adrienmissioux/Documents/Epitech/cpp_arcade/
//
// Made by Adrien Missioux
// Login   <adrien.missioux@epitech.eu@epitech.eu>
//
// Started on  Wed Mar 15 16:46:37 2017 Adrien Missioux
// Last update Sun Apr  9 21:01:45 2017 Adrien Missioux
//

#ifndef _ALIB_HPP_
#define _ALIB_HPP_

#include <iostream>
#include <dlfcn.h>
#include <string>
#include <vector>
#include <dirent.h>
#include "GetLib.hpp"

class ALib {

  enum Keys {
    GraphicsP = 0,
    GraphicsN = 1,
    GameP     = 2,
    GameN     = 3,
    Exit      = 4
  };

protected:
  std::string _path;
  std::vector<std::string>  _allLib;
  std::vector<std::string>  _allGames;
  int _numLib;
  int _numGame;
  void *_handle;
  void *_handleGame;
  bool statu;
public:
  ALib();
  ALib(const std::string & path);
  ALib(ALib & actual);
  ~ALib();
  std::string getPath() const;
  void setNumLib(int num);
  void setNumGame(int num);
  void *getHandle() const;
  void *getHandleGame() const;
  void *load(const std::string & p);
  void *sym(void *, const std::string & func);
  int getNumLib() const;
  int getNumGame() const;
  std::vector<std::string>  getAllLib() const;
  std::vector<std::string>  getAllGames() const;
  std::string getLib(std::string) const;
  ALib & operator=(ALib *);
  bool operator!=(ALib * ala);
  void setHandleGame(void *handle);
  bool getStatu() const;
};

#endif
