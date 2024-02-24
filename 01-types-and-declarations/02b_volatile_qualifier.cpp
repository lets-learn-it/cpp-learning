#include <iostream>
#include <chrono>
#include <thread>

/*
 * volatile is a hint to a compiler to avoid aggressive optimization involving the object because
 * the value of the object can be changed by means that are not detectable by the compiler.
 *
 * https://stackoverflow.com/questions/72552/why-does-volatile-exist
 * it is needed if you are reading from a spot in memory that is completely separate process/device may write to.
 */

int main() {
  volatile int x = 10;

  while(x == 10) {
    std::cout << "x is 10" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }
}
