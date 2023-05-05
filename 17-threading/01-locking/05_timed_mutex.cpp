#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std::literals;

int main(int argc, char const *argv[]) {
  std::timed_mutex mt;

  mt.lock();

  std::cout << "Checking if lock is available" << std::endl;

  if (!mt.try_lock()) std::cout << "Lock already held" << std::endl;

  if (!mt.try_lock_for(2s)) std::cout << "Lock already held" << std::endl;

  auto now = std::chrono::steady_clock::now();
  if (!mt.try_lock_until(now + 2s)) std::cout << "Lock already held" << std::endl;

  return 0;
}
