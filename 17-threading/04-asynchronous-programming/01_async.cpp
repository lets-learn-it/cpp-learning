#include <iostream>
#include <thread>
#include <future>

unsigned long long fibonacci(unsigned long long n) {
  if (n <= 1)
    return 1;
  return fibonacci(n - 1) + fibonacci(n-2);
}

int main() {
  auto result = std::async(fibonacci, 40);

  std::cout << result.get() << std::endl;

  return 0;
}
