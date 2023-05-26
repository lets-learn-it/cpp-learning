#include <iostream>
#include "Game.h"
#include <termios.h>
#include <unistd.h>
#include <thread>
#include <chrono>

int main() {
  termios oldSettings, newSettings;
  tcgetattr(STDIN_FILENO, &oldSettings);
  newSettings = oldSettings;
  newSettings.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newSettings);

  Game game(60, 20);

  std::thread thr([&game]() {
    while(true) {
      std::cerr << "Hi";
      game.input();
      std::cerr << "Hi";
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
  });

  while(true) {
    game.draw();
    game.logic();
    std::cerr << "Hello";
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  tcsetattr(STDIN_FILENO, TCSANOW, &oldSettings);
  return 0;
}
