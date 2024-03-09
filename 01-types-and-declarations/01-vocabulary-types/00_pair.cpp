#include <iostream>
#include <utility>

int main() {
  std::pair<int, double> p1 = std::make_pair(1, 3.14);
  std::pair<int, std::string> p2 = {25, "parikshit"};

  // access
  std::cout << std::get<0>(p1) << " " << std::get<1>(p1) << std::endl;
  std::cout << std::get<int>(p1) << " " << std::get<double>(p1) << std::endl;
  std::cout << p1.first << " " << p1.second << std::endl;

  // structured binding (https://en.cppreference.com/w/cpp/language/structured_binding)
  auto& [a, b] = p1;
  std::cout << a << " " << b << std::endl;

  return 0;
}