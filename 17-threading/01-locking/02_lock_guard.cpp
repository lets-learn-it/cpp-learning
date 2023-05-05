#include <iostream>
#include <thread>
#include <mutex>

using namespace std::literals;

int rounds = 1'00'000;

std::mutex mt;

void inc(int &a) {
  for (int i = 0; i < rounds; i++) {
    // when lg goes out of scope, mutex is unlocked automatically
    std::lock_guard<std::mutex> lg(mt);
    a ++;
  }
}

void dec(int &a) {
  for (int i = 0; i < rounds; i++) {
    // when lg goes out of scope, mutex is unlocked automatically
    // no need to unlock inside catch
    try {
      std::lock_guard<std::mutex> lg(mt);
      a --;
      throw std::exception();
    } catch (std::exception& e) {

    }
  }
}

int main(int argc, char const *argv[]) {
  int i = 0;
  std::thread thr1(inc, std::ref(i)), thr2(dec, std::ref(i));

  thr1.join(); thr2.join(); 

  std::cout << "Value of i: " << i << " should be " << 0 << std::endl;
  return 0;
}
