#include <iostream>
#include <exception>

int main() {
  std::set_terminate([]() {
    std::cout << "set_terminate exception handled" << std::endl;
    std::abort();
  });

  throw 1;

  return 0;
}