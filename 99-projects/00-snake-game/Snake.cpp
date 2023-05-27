#include <deque>
#include <iostream>
#include <cassert>
#include "Snake.h"

Snake::Snake(unsigned int headX, unsigned int headY) {
  snake.push_back(std::make_pair(headX, headY));
  direction = RIGHT;
}

Snake::~Snake() {}

SnakePosition Snake::move_and_eat(const std::pair<unsigned int, unsigned int>& food) {
  mt.lock();

  std::pair<unsigned int, unsigned int> head = snake.front();

  if (direction == STOP) {
    mt.unlock();
    return std::make_pair(NONE, head);
  }
  
  switch (direction) {
  case RIGHT:
    snake.push_front(std::make_pair(head.first+1, head.second));
    break;
  case LEFT:
    snake.push_front(std::make_pair(head.first-1, head.second));
    break;
  case DOWN:
    snake.push_front(std::make_pair(head.first, head.second+1));
    break;
  case UP:
    snake.push_front(std::make_pair(head.first, head.second-1));
    break;
  case STOP:
    break;
  }
  
  // std::cout << "(" << head.first << ", " << head.second << "), (" << food.first << ", " << food.second << ")";
  head = snake.front();
  if (head.first != food.first || head.second != food.second) {
    snake.pop_back();
    mt.unlock();
    return std::make_pair(NONE, head);
  }

  mt.unlock();
  return std::make_pair(ATE, head);
}

void Snake::change_direction(SnakeDirection d) {
  mt.lock();
  direction = d;
  mt.unlock();
}

void Snake::draw(char *boardBuff, unsigned int width, unsigned int height) {
  mt.lock();
  unsigned int pos = 0;
  for (const auto &pair : snake) {
    pos = (pair.second) * (width+1) + pair.first;
    boardBuff[pos] = 'o';
  }
  pos = (snake.front().second) * (width+1) + snake.front().first;
  boardBuff[pos] = 'O';
  mt.unlock();
}
