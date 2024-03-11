#include <iostream>
#include <variant>

int main() {
  // create variant for number
  std::variant<int, float> num;
  num = 42;  // integer is held

  // check what is held
  std::cout << "Index held: " << num.index() << std::endl;

  // get value
  std::cout << "value using index: " << std::get<0>(num) << std::endl;
  std::cout << "value using type: " << std::get<int>(num) << std::endl; // if type is unique

  num = (float)42.7;

  // wrong access
  try {
    std::cout << "value: " << std::get<int>(num) << std::endl;
  } catch (std::bad_variant_access e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}