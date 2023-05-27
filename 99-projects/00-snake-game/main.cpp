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
      if (game.input()) break;
      // std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
  });

  while(true) {
    if (game.logic()) break;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  thr.join();

  tcsetattr(STDIN_FILENO, TCSANOW, &oldSettings);
  return 0;
}
