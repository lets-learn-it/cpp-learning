/* C++17 & later */
#include <iostream>
#include <any>

void print(const std::any& value) {
  if (value.type() == typeid(int)) {
    std::cout << "Integer: " << std::any_cast<int>(value) << std::endl;
  } else if (value.type() == typeid(double)) {
    std::cout << "Double: " << std::any_cast<double>(value) << std::endl;
  } else if (value.type() == typeid(char)) {
    std::cout << "Char: " << std::any_cast<char>(value) << std::endl;
  } else {
    std::cout << "Unknown type " << value.type().name() << std::endl;
  }
}

int main() {
  int intValue = 42;
  double doubleValue = 3.14;
  char charValue = 'A';
  std::string name = "Parikshit";

  print(intValue);
  print(doubleValue);
  print(charValue);
  print(name);

  return 0;
}