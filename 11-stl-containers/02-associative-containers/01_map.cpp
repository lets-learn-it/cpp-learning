#include <iostream>
#include <map>
#include <string>
#include <tuple>

/*
 * std::map is sorted associative container that contains key-value pairs with unique keys
 * Keys are sorted by using comparision function Compare.
 *
 * Search, removal and insertion operations have logarithmic complexity.
 * Usually implemented as Red-Black trees.
 *
 */

template<typename T1, typename T2>
void print_map(const char *message, std::map<T1, T2> &s) {
  std::cout << message << ": " << std::endl;
  for(auto& [k, v] : s) {
    std::cout << k << ": " << v << std::endl;
  }
  std::cout << std::endl;
}

int main() {
  std::map<std::string, std::string> people{{"Parikshit", "I am 26"}, {"XYZ", "I dont exist"}};
  print_map("people", people);

  return 0;
}