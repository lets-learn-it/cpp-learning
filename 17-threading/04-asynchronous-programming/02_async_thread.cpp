#include <iostream>
#include <thread>
#include <future>

int func(int a) {
  std::cout << "Thread id: " << std::this_thread::get_id() << std::endl;
  return a;
}

int main() {
  std::cout << "Main thread id: " << std::this_thread::get_id() << std::endl;

  // create separate thread
  auto result1 = std::async(std::launch::async, func, 1); 
  std::cout << "return value: " << result1.get() << std::endl;

  // run on main thread
  auto result2 = std::async(std::launch::deferred, func, 2);
  std::cout << "return value: " << result2.get() << std::endl;

  return 0;
}
