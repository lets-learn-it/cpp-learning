#include <iostream>
#include <thread>
#include <atomic>

std::atomic<int> num = 0;
int rounds = 1'000'000;

void inc() {
  for (int i=0;i<rounds;i++) {
    num++;
  }
}

int main() {
  std::thread thr1(inc), thr2(inc);

  thr1.join(); thr2.join();

  std::cout << "Total num = " << num << std::endl;
  return 0;
}
