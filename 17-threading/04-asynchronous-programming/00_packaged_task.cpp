#include <iostream>
#include <thread>
#include <future>

int main() {
  std::packaged_task<int(int, int)> ptask([](int a, int b) {return a + b;});

  std::future<int> fut = ptask.get_future();
  std::thread t(std::move(ptask), 6, 7);

  t.join();

  std::cout << "addition = " << fut.get() << std::endl;

  return 0;
}
