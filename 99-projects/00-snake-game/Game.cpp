#include "Game.h"
#include <algorithm>
#include <ctime>

unsigned int random_between(unsigned int a, unsigned int b) {
  return a + (rand() % (b-a));
}

Game::Game(unsigned int width, unsigned int height) {
  board = std::make_pair(width, height);
  snake = new Snake(width/2, height/2);
  score = 0;
  std::srand(static_cast<unsigned>(std::time(nullptr)));
  food = std::make_pair(random_between(1, width-1), random_between(1, height-1));
  boardBuff = new char[(width + 2) * height];
}

Game::~Game() {
  delete boardBuff;
  delete snake;
}

void Game::draw() {
  system("clear");
  unsigned int pos = 0;
  std::fill(boardBuff, boardBuff + (board.first + 1) * board.second, ' ');
  
  std::fill(boardBuff, boardBuff + board.first, '-');
  boardBuff[0] = '+'; boardBuff[board.first-1] = '+';
  pos = board.first;
  boardBuff[pos] = '\n'; pos++;

  for (unsigned int i=1; i<board.second-1; i++) {
    for (unsigned int j=0; j<board.first-1; j++) {
      if (j==0) { boardBuff[pos] = '|'; pos++; continue; }
      if (i==food.second && j==food.first) { boardBuff[pos] = '*'; pos++; continue; }
      boardBuff[pos] = ' '; pos ++;
    }
    boardBuff[pos] = '|'; pos++;
    boardBuff[pos] = '\n'; pos++;
  }
  
  boardBuff[pos] = '+';
  std::fill(boardBuff + pos + 1, boardBuff + pos + board.first, '-');
  boardBuff[pos+board.first-1] = '+';

  snake->draw(boardBuff, board.first, board.second);
  
  std::cout << boardBuff << std::endl;
}

void Game::input() {
  char ch;
  std::cin >> ch;
  switch (ch) {
  case 'w':
    snake->change_direction(UP);
    break;
  case 'a':
    snake->change_direction(LEFT);
    break;
  case 's':
    snake->change_direction(DOWN);
    break;
  case 'd':
    snake->change_direction(RIGHT);
    break;
  default:
    break;
  }
}

void Game::logic() {
  if (snake->move_and_eat(food)) {
    food = std::make_pair(random_between(1, board.first-1), random_between(1, board.second-1));
  }
}
