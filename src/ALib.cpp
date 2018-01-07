//
// ALib.cpp for ALib in /Users/adrienmissioux/Documents/Epitech/cpp_arcade/
//
// Made by Adrien Missioux
// Login   <adrien.missioux@epitech.eu@epitech.eu>
//
// Started on  Wed Mar 15 16:46:21 2017 Adrien Missioux
// Last update Sun Apr  9 21:01:32 2017 Adrien Missioux
//

#include "ALib.hpp"

ALib::ALib() : _path("") {
  std::vector<std::string> tmp;
  this->_handle = NULL;
  this->_handleGame = NULL;
  this->_numLib = 0;
  this->_numGame = 0;
  this->_allLib = tmp;
  this->_allGames = tmp;
}

ALib::ALib(std::string const & p) : _path(p) {

  // init _allLib
  DIR *dir;
  struct dirent *ent;
  if ((dir = opendir ("./lib")) != NULL) {
    while ((ent = readdir (dir)) != NULL) {
      std::string tmp(ent->d_name);
      if(tmp.substr(tmp.find_last_of(".") + 1) == "so") {
            this->_allLib.push_back("./lib/" + tmp);
          }
    }
    closedir (dir);
  } else {
      std::cerr << "Cannot open lib directory." << std::endl;
  }
  for (int i = 0; i < (int)this->_allLib.size(); i++)
    {
      if (this->_path.find(this->_allLib.at(i)) != std::string::npos) {
        this->_numLib = i;
      }
    }

  // init _allGames

  DIR *dir2;
  struct dirent *ent2;
  if ((dir2 = opendir ("./games")) != NULL) {
    while ((ent2 = readdir (dir2)) != NULL) {
      std::string tmp(ent2->d_name);
      if(tmp.substr(tmp.find_last_of(".") + 1) == "so") {
            this->_allGames.push_back("./games/" + tmp);
          }
    }
    closedir (dir2);
  } else {
      std::cerr << "Cannot open lib directory." << std::endl;
  }
  this->_numGame = 0;
  this->_handleGame = NULL;
  // init others
  this->statu = false;
  this->_handle = dlopen(p.c_str(), RTLD_LAZY);
  if (!this->_handle) {
      std::cerr << "Cannot open library: " << dlerror() << std::endl;
  }
}

ALib::ALib(ALib & actual) {
  this->_handle = actual._handle;
  this->_handleGame = actual._handleGame;
  this->_numLib = actual._numLib;
  this->_numGame = actual._numGame;
  this->_allLib = actual._allLib;
  this->_allGames = actual._allGames;
}

ALib::~ALib() {
  if (this->_handle)
    dlclose(this->_handle);
}

std::string ALib::getPath() const {
  return(this->_path);
}

void *ALib::getHandle() const {
  return(this->_handle);
}

void *ALib::getHandleGame() const {
  return(this->_handleGame);
}

int ALib::getNumLib() const {
  return (this->_numLib);
}

int ALib::getNumGame() const {
  return (this->_numGame);
}

std::vector<std::string>  ALib::getAllLib() const {
  return (this->_allLib);
}

std::vector<std::string>  ALib::getAllGames() const {
  return (this->_allGames);
}

std::string  ALib::getLib(std::string a) const {
  return (a);
}

void *ALib::load(std::string const & p) {
  void *tmp = dlopen(p.c_str(), RTLD_LAZY);
  if (!tmp) {
      std::cerr << "Cannot open library: " << dlerror() << std::endl;
  }
  return (tmp);
}

void *ALib::sym(void *handle, std::string const & func) {
  void *tmp = dlsym(handle, func.c_str());
  const char *dlsym_error = dlerror();
  if (dlsym_error)
  {
    std::cerr << "Cannot load symbol : " << dlsym_error << std::endl;
    throw "dlsym_error";
  }
  return (tmp);
}

  ALib & ALib::operator=(ALib * ala) {
    this->_path = ala->_path;
    this->_allLib = ala->_allLib;
    this->_numLib = ala->_numLib;
    if (this->_handle)
      dlclose(this->_handle);
    this->_handle = ala->_handle;
    return *this;
  }

  bool ALib::operator!=(ALib * ala) {
    if (this != ala)
      return true;
    else
      return false;
  }

bool ALib::getStatu() const {
  return this->statu;
}

void ALib::setHandleGame(void *handle)
{
  this->_handleGame = handle;
}

void ALib::setNumLib(int num) {
    this->_numLib = num;
  }

void ALib::setNumGame(int num) {
    this->_numGame = num;
  }
