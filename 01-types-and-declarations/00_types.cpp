#include <iostream>
#include <climits>
using namespace std;

int main() {
  int a = 10;
  float b = 34.5f;
  double c = 34.565;
  long d = 1323l;
  char e = 'P';
  bool f = true;

  cout << "int a: " << a << ", sizeof int: " << sizeof(a) << endl;
  cout << "float b: " << b << ", sizeof float: " << sizeof(b) << endl;
  cout << "double a: " << a << ", sizeof double: " << sizeof(c) << endl;
  cout << "long a: " << a << ", sizeof long: " << sizeof(d) << endl;
  cout << "char e: " << e << ", sizeof char: " << sizeof(e) << endl;
  cout << "bool f: " << f << ", sizeof bool: " << sizeof(f) << endl;

  return 0;
}