#include "Snake.h"
#include <iostream>

#ifndef __GAME__
#define __GAME__

class Game {
private:
  Snake *snake;
  std::pair<unsigned int, unsigned int> board;
  std::pair<unsigned int, unsigned int> food;
  unsigned int score;
  char *boardBuff;
  bool over;
  
public:
  Game(unsigned int width, unsigned int height);
  ~Game();

  void draw();
  bool input();
  bool logic();
};

#endif