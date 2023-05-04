#include <iostream>
#include <thread>
using namespace std::literals;

int rounds = 1'00'000;

void inc(int &a) {
  for (int i = 0; i < rounds; i++) {
    a ++;
  }
}

int main(int argc, char const *argv[]) {
  int i = 0;
  std::thread thr1(inc, std::ref(i)), thr2(inc, std::ref(i));

  thr1.join(); thr2.join(); 

  std::cout << "Value of i: " << i << " should be " << 2 * rounds << std::endl;
  return 0;
}
