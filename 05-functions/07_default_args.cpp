#include <iostream>
using namespace std;

void func(int, int, int, int);

void func(int a, int b, int c=1, int d=1) {
  cout << "a: " << a << " "
       << "b: " << b << " "
       << "c: " << c << " "
       << "d: " << d << endl;
}

int main() {
  int a = 10, b = 20, c = 30, d = 40;

  func(a, b);

  func(a, b, c);

  func(a,b,c,d);

  return 0;
}
