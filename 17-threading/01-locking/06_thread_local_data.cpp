#include <iostream>
#include <thread>

thread_local int num;

void inc() {
  num++;
  std::cout << "Value in thread (" << std::this_thread::get_id() << ") :" << num << std::endl;
}

int main() {
  std::thread thr1(inc), thr2(inc);
  
  thr1.join(); thr2.join();

  std::cout << "Value in main thread: " << num << std::endl;
  return 0;
}

