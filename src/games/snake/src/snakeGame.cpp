//
// Game.cpp for  in /home/munoz_d/Desktop/snake/src
//
// Made by David Munoz
// Login   <david.munoz@epitech.eu>
//
// Started on  Fri Mar 31 13:48:52 2017 David Munoz

// Last update Sun Apr  9 20:54:11 2017 David Munoz
//

#include "libGra.h"
#include "snakeGame.h"
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <unistd.h>

extern "C" void Play(void);

int x = 4;
int y = 4;
int tmpUp = 0;
int tmpDown = 0;
int tmpRight = 0;
int tmpLeft = 0;

snakeGame::snakeGame()
{
  str_score = "";

  // initial map
  this->initMap.push_back("1111111111");
  this->initMap.push_back("1000000001");
  this->initMap.push_back("1000060001");
  this->initMap.push_back("1000000001");
  this->initMap.push_back("1000000001");
  this->initMap.push_back("1000000001");
  this->initMap.push_back("1000000001");
  this->initMap.push_back("1000000001");
  this->initMap.push_back("1000000001");
  this->initMap.push_back("1111111111");

  // GetMap struct
  // this->map = (arcade::GetMap *)malloc(sizeof(arcade::GetMap) + (sizeof(arcade::TileType) * 9 * 9));
  // this->map->width = 9;
  // this->map->height = 9;
  // this->map->type = arcade::CommandType::GET_MAP;
  // size_t i = 0;
  // while (i < 9)
  // {
  //   size_t j = 0 ;
  //   while (j < 9)
  //   {
  //     if (this->initMap[i][j] == '0')
  //       this->map->tile[j * 9 + i] = arcade::TileType::EMPTY;
  //     else if (this->initMap[i][j] == '1')
  //       this->map->tile[j * 9 + i] = arcade::TileType::BLOCK;
  //     else
  //       this->map->tile[j * 9 + i] = arcade::TileType::OTHER;
  //     j++;
  //   }
  //   i++;
  // }
  // Position struct
  this->player.x = 4;
  this->player.x = 4;
  this->pos.push_back(this->player);
  // WhereAmI struct
  // this->where = (arcade::WhereAmI *)malloc(sizeof(arcade::WhereAmI) + (this->pos.size() * sizeof(arcade::Position)));
  // this->where->type = arcade::CommandType::WHERE_AM_I;
  // int i = 0;
  // this->where->lenght = this->pos.size();
  // for (std::vector<arcade::Position>::const_iterator it = this->pos.begin() ; it != this->pos.end(); ++it)
  //   this->where->position[i] = *it;

  _choices.insert(std::make_pair(arcade::CommandType::WHERE_AM_I, std::bind(&snakeGame::getWhereAmI, this)));
  _choices.insert(std::make_pair(arcade::CommandType::GET_MAP, std::bind(&snakeGame::getMap, this)));
  _choices.insert(std::make_pair(arcade::CommandType::GO_UP, std::bind(&snakeGame::goUp, this)));
  _choices.insert(std::make_pair(arcade::CommandType::GO_DOWN, std::bind(&snakeGame::goDown, this)));
  _choices.insert(std::make_pair(arcade::CommandType::GO_LEFT, std::bind(&snakeGame::goLeft, this)));
  _choices.insert(std::make_pair(arcade::CommandType::GO_RIGHT, std::bind(&snakeGame::goRight, this)));
  _choices.insert(std::make_pair(arcade::CommandType::GO_FORWARD, std::bind(&snakeGame::goForward, this)));
  _choices.insert(std::make_pair(arcade::CommandType::SHOOT, std::bind(&snakeGame::shoot, this)));
  _choices.insert(std::make_pair(arcade::CommandType::ILLEGAL, std::bind(&snakeGame::illegal, this)));
  _choices.insert(std::make_pair(arcade::CommandType::PLAY, std::bind(&snakeGame::play, this)));
}

snakeGame::~snakeGame()
{}

Snake_obj snakeGame::getSnake() const
{
  return (this->snake);
}

void	snakeGame::setSnake(Snake_obj _snake)
{
  this->snake = _snake;
}

void    snakeGame::setFood(Food_obj _food)
{
  this->food = _food;
}

Food_obj snakeGame::getFood() const
{
  return (this->food);
}

void snakeGame::selector(arcade::CommandType num) {
  this->_choices[num]();
}

void snakeGame::getWhereAmI() {

static int j = 0;



     std::cerr << "WhereAmI " << std::endl;
    arcade::WhereAmI *where;

    where = (arcade::WhereAmI *)malloc(sizeof(arcade::WhereAmI) + (1 * sizeof(arcade::Position)));
    where->type = arcade::CommandType::WHERE_AM_I;
    arcade::Position tmp;


    tmp.x = x;
    tmp.y = y;

    if (tmpUp == 1)
    {
      y--;
      tmpUp = 0;
    }
    else if (tmpDown == 1)
    {
      y++;
      tmpDown = 0;
    }
    where->lenght = this->pos.size();
    where->position[0] = tmp;

    if (tmpLeft == 1)
    {
      x--;
      tmpLeft = 0;
    }
    else if (tmpRight == 1)
    {
      x++;
      tmpRight = 0;
      j = 1;
    }
    if (j == 0) {
      x++;
      j = 1;
    }
    write(1, where, sizeof(arcade::WhereAmI) + (1 * sizeof(arcade::Position)));
}
void  snakeGame::getMap() const {
    // std::cout << "GetMap" << std::endl;
    arcade::GetMap *_mapTmp;
    _mapTmp = (arcade::GetMap *)malloc(sizeof(arcade::GetMap) + (sizeof(arcade::TileType) * 10 * 10));
    _mapTmp->width = 10;
    _mapTmp->height = 10;
    _mapTmp->type = arcade::CommandType::GET_MAP;
    size_t i = 0;
    while (i < 10)
    {
      size_t j = 0 ;
      while (j < 10)
      {
        if (this->initMap[i][j] == '0')
          _mapTmp->tile[j * _mapTmp->height + i] = arcade::TileType::EMPTY;
        else if (this->initMap[i][j] == '1')
          _mapTmp->tile[j * _mapTmp->height + i] = arcade::TileType::BLOCK;
        else if (this->initMap[i][j] == '6')
          _mapTmp->tile[j * _mapTmp->height + i] = arcade::TileType::POWERUP;
        else
          _mapTmp->tile[j * _mapTmp->height + i] = arcade::TileType::OTHER;
        j++;
      }
      i++;
    }
    write(1, _mapTmp, sizeof(arcade::GetMap) + (sizeof(arcade::TileType) * 10 * 10));
    free(_mapTmp);
}
void snakeGame::goUp() {
  std::cerr << "goUp" << std::endl;
      y--;
      tmpUp = 1;
}
void snakeGame::goDown() {
 std::cerr << "goDown" << std::endl;
      y++;
      tmpDown = 1;
}
void snakeGame::goLeft() {
 std::cerr << "goLeft" << std::endl;
      x--;
      tmpLeft = 1;
}
void snakeGame::goRight() {
 std::cerr << "goRight" << std::endl;
      x++;
      tmpRight = 1;
}
void snakeGame::goForward() {
  // std::cout << "goForward" << std::endl;
}
void snakeGame::shoot() {
  // std::cout << "shoot" << std::endl;
}
void snakeGame::illegal() {
  // std::cout << "illegal" << std::endl;
}
void snakeGame::play() {
  // std::cout << "play" << std::endl;
  Play();
}

extern "C" int  playSnake(void *handle)
{
  libGra        tmp(handle);
  snakeGame     game_snake;
  Snake_obj     snake;
  Food_obj      food;
  Map   map;
  int   event;
  int   done;

  done = SNAKE_OK;
  if (tmp.initLib() == SNAKE_ERR)
    return (SNAKE_ERR);
  tmp.render(game_snake.getSnake().get_frontX(), game_snake.getSnake().get_frontY(), 0, 0, snake.get_collision_state(), game_snake.get_score());
  while (done == SNAKE_OK)
    {
      switch (event = tmp.getEvent())
        {
        case (GO_LEFT):
          if (game_snake.getSnake().get_direction() != GO_RIGHT)
            {
	      snake = game_snake.getSnake();
              snake.go_left();
              game_snake.setSnake(snake);
            }
          game_snake.collision(map);
          tmp.render(game_snake.getSnake().get_frontX(), game_snake.getSnake().get_frontY(), game_snake.getFood().get_posX(), game_snake.getFood().get_posY(), snake.get_collision_state(), game_snake.get_score());
          game_snake.getSnake().self_collide();
          map.clear_map();
          break;
        case (GO_RIGHT):
          if (game_snake.getSnake().get_direction() != GO_LEFT)
            {
	      snake = game_snake.getSnake();
              snake.go_right();
              game_snake.setSnake(snake);
            }
	  game_snake.collision(map);
	  tmp.render(game_snake.getSnake().get_frontX(), game_snake.getSnake().get_frontY(), game_snake.getFood().get_posX(), game_snake.getFood().get_posY(), snake.get_collision_state(), game_snake.get_score());
          game_snake.getSnake().self_collide();
          map.clear_map();
          break;
        case (GO_UP):
          if (game_snake.getSnake().get_direction() != GO_DOWN)
            {
	      snake = game_snake.getSnake();
              snake.go_up();
              game_snake.setSnake(snake);
            }
          game_snake.collision(map);
	  tmp.render(game_snake.getSnake().get_frontX(), game_snake.getSnake().get_frontY(), game_snake.getFood().get_posX(), game_snake.getFood().get_posY(), snake.get_collision_state(), game_snake.get_score());
          game_snake.getSnake().self_collide();
          map.clear_map();
          break;
        case (GO_DOWN):
          if (game_snake.getSnake().get_direction() != GO_UP)
            {
	      snake = game_snake.getSnake();
              snake.go_down();
              game_snake.setSnake(snake);
            }
          game_snake.collision(map);
	  tmp.render(game_snake.getSnake().get_frontX(), game_snake.getSnake().get_frontY(), game_snake.getFood().get_posX(), game_snake.getFood().get_posY(), snake.get_collision_state(), game_snake.get_score());
          game_snake.getSnake().self_collide();
          map.clear_map();
          break;
        case (PREVIOUS_LIB):
        case (NEXT_LIB):
        case (PREVIOUS_GAME):
        case (NEXT_GAME):
        case (RESTART_GAME):
        case (BACK_MENU):
	  {
	    tmp.closeLib();
	    return (event);
	  }
        case (0):
	  done = 1;
        case (GO_FORWARD):
          game_snake.collision(map);
	  snake = game_snake.getSnake();
          tmp.render(game_snake.getSnake().get_frontX(), game_snake.getSnake().get_frontY(), game_snake.getFood().get_posX(), game_snake.getFood().get_posY(), snake.get_collision_state(), game_snake.get_score());
	  game_snake.setSnake(snake);
          game_snake.getSnake().self_collide();
          map.clear_map();
          break;
        }
    }
  tmp.closeLib();
  return (4);
}
