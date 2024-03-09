#include <iostream>
#include <utility>
#include <expected>

enum class errors {
  divide_by_zero,
  divide_by_2_not_allowed
};

std::expected<int, std::string> divide(int a, int b) {
  if (b == 0) return std::unexpected("");
  if (b == 2) return std::unexpected(":");
  return int(a/b);
}

int main() {
  std::cout << divide(7, 3).value_or(5) << std::endl;
  std::cout << divide(7, 0).value_or(5) << std::endl;
  std::cout << divide(7, 2).value_or(5) << std::endl;
  return 0;
}