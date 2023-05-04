#include <iostream>
#include <vector>
using namespace std;

int main() {
  int (*simple_sum)(int, int) = [](int a, int b) {
    return a + b;
  };

  auto simple_sum2 = [](int a, int b) -> int {
    return a + b;
  };

  cout << "simple_sum(4, 5) = " << simple_sum(4,5) << endl;
  cout << "simple_sum2(4, 5) = " << simple_sum2(4,5) << endl;

  /* 
   * Local Capture
   * - capture all variables in scope
   * [=] all by value
   * [&] all by reference
   * - more selective
   * [=, &x] x by reference, all others by value
   * [&, =a, =b] a & b by value, all others by reference
   */
  int c = 100;
  int d = 200;

  // capture by reference
  auto double_c_ref = [&c]() {
    c = 2 * c;
    return c;
  };

  cout << "1. double_by_ref() = " << double_c_ref() << ", value of c = " << c << endl;
  cout << "2. double_by_ref() = " << double_c_ref() << ", value of c = " << c << endl;

  // c will be read only
  auto double_c_value = [c]() {
    return 2 * c;
  };

  cout << "1. double_by_value() = " << double_c_value() << ", value of c = " << c << endl;
  cout << "2. double_by_value() = " << double_c_value() << ", value of c = " << c << endl;

  // capture by move
  vector<int> vec{1,2,3,4,5};
  cout << "size of vec (before lambda):" << vec.size() << endl; 

  [vec = move(vec)]() {
    cout << "size of vec (inside lambda):" << vec.size() << endl; 
  }();

  cout << "size of vec (after lambda):" << vec.size() << endl; 

  return 0;
}