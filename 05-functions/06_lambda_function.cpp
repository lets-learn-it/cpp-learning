#include <iostream>
using namespace std;

int main() {
  int (*simple_sum)(int, int) = [](int a, int b) {
    return a + b;
  };

  cout << simple_sum(4,5);
  return 0;
}