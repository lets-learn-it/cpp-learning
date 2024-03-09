#include <iostream>
#include <tuple>

int main() {
  // id, name & age tuple
  std::tuple<uint16_t, uint8_t, std::string> t1 = std::make_tuple(1, 55, "Parikshit");
  std::tuple<uint16_t, uint8_t, std::string> t2 = {1, 26, "Parikshit"};
  std::tuple<uint16_t, uint8_t, std::string> t3{1, 26, "Parikshit"};

  // access
  std::cout << std::get<0>(t1) << ", " << std::get<1>(t1) << ", " << std::get<2>(t1) << std::endl;
  std::cout << std::get<uint16_t>(t1) << ", " << std::get<uint8_t>(t1) << ", " << std::get<std::string>(t1) << std::endl;

  // using tie
  uint8_t age;
  uint16_t id;
  std::string name;
  std::tie(id, age, name) = t1;
  std::cout << id << ", " << age << ", " << name << std::endl;

  // C++17 structured binding:
  auto& [a, b, c] = t1;
  std::cout << a << ", " << b << ", " << c << std::endl;

  return 0;
}