#include <deque>
#include <mutex>

#ifndef __SNAKE__
#define __SNAKE__



enum SnakeDirection {
  STOP = 0,
  RIGHT,
  LEFT,
  DOWN,
  UP
};

enum LastAction {
  NONE,
  ATE
};

typedef std::pair<LastAction, std::pair<unsigned int, unsigned int>> SnakePosition;

class Snake {
private:
  std::deque<std::pair<unsigned int, unsigned int>> snake;
  SnakeDirection direction;
  std::mutex mt;
public:
  Snake(unsigned int headX, unsigned int headY);
  ~Snake();

  SnakePosition move_and_eat(const std::pair<unsigned int, unsigned int>& food);
  void change_direction(SnakeDirection d);
  void draw(char *board, unsigned int width, unsigned int height);
};

#endif
