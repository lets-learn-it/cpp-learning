#include <iostream>
#include <optional>

std::optional<std::string> get_string(bool b) {
  if (b) return "Parikshit";
  return {};
  // return std::nullopt;
}

int main() {
  auto x1 = get_string(true);
  auto x2 = get_string(false);

  // check if value is present
  if (x1.has_value()) std::cout << "using x1.value(): " << x1.value() << std::endl;
  if (x1.has_value()) std::cout << "using *x1: " << *x1 << std::endl;
  if (x2.has_value()) std::cout << "using x1.value(): " << x2.value() << std::endl;

  // check if, else set
  std::cout << x1.value_or("no value") << std::endl;
  std::cout << x2.value_or("no value") << std::endl;

  // exception if value not present
  try {
    auto t = x2.value();
  } catch (std::bad_optional_access e) {
    std::cout << e.what() << std::endl;
  }

  // destroy contained value using reset


  return 0;
}