#include <iostream>
#include <thread>
#include <mutex>

/* 
 * https://en.cppreference.com/w/cpp/thread/recursive_mutex
 * exclusive, recursive ownership
 * - once thread gets recursive_mutex then that thread can call lock / try_lock on it multiple times.
 *   but to unlock mutex, same thread has to call unlock exactly same number of times.
 * - 
 */

using namespace std::literals;

std::recursive_mutex rmt;

void inc(int &a, const char *name) {
  if (a % 4 == 0) {
    a++;
    return;
  }
  // try lock
  while(!rmt.try_lock()) {
    std::cout << name << ": lock is taken\n";
    std::this_thread::sleep_for(0.5s);
  }
  std::this_thread::sleep_for(0.1s);
  std::cout << name << ": got lock (" << a << ")\n";
  a++;
  inc(a, name);
  rmt.unlock();
  std::cout << name << ": released lock (" << a << ")\n";
}

int main(int argc, char const *argv[]) {
  int i = 1;
  std::thread thr1(inc, std::ref(i), "thr1"), thr2(inc, std::ref(i), "thr2");

  thr1.join(); thr2.join(); 
  return 0;
}
