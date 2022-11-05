#include <iostream>
using namespace std;

int add(int a, int b);

int main() {
  int a = 10;
  int b = 45;

  int c = add(a, b);

  cout << a << b << c << endl;
  return 0;
}

int add(int a, int b) {
  return a + b;
}