#include <iostream>
#include <thread>
#include <mutex>

using namespace std::literals;

int rounds = 1'00'000;

std::mutex mt;

void inc(int &a) {
  int i = 0;
  while (i < rounds) {
    {
      std::lock_guard<std::mutex> lg(mt);
      a++;
    } // end of lg
    i++; // not critical section
  }
}

// another solution
// if exception occurs and unlock not called, no issue
// when ul goes out of scope, mutex will be unlocked.
// Other features of unique_lock
// std::unique_lock<std::mutex> ul(mt, mechanism);
//  - std::defer_lock : does not lock mutex only owns, can be locked later using ul.lock()
//  - std::adopt_lock : take ownership of already locked mutex. (except for recursive mutexes)
//  - std::try_lock   : like calling try_lock
void dec(int &a) {
  int i = 0;
  while (i < rounds) {
    std::unique_lock<std::mutex> ul(mt);
    a--;
    ul.unlock();  
    i++; // not critical section
  }
}

int main(int argc, char const *argv[]) {
  int i = 0;
  std::thread thr1(inc, std::ref(i)), thr2(dec, std::ref(i));

  thr1.join(); thr2.join(); 

  std::cout << "Value of i: " << i << " should be " << 0 << std::endl;
  return 0;
}
