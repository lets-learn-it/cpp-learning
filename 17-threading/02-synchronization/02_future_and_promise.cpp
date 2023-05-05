#include <iostream>
#include <thread>
#include <future>

using namespace std::literals;

int n = 5;

void produce(std::promise<int>& px) {
  int f = 1;
  for(int i=1;i<n;i++) f *= i;
  std::this_thread::sleep_for(2s);
  px.set_value(f);
}

void consume(std::future<int>& fx) {
  int x = fx.get();
  std::cout << "fact(" << n << ") = " << x << std::endl;
}

int main() {
  std::promise<int> promise;
  std::future<int> f = promise.get_future();
  std::thread fut(consume, std::ref(f)), prom(produce, std::ref(promise));

  fut.join(); prom.join();

  return 0;
}
