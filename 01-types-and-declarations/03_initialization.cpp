#include <iostream>
using namespace std;

int main() {
  /*
   * Initialization on Stack
   */
  int a; // uninitialized
  cout << "Uninitialized: " << a << endl;

  int b = 10; // copy initialization
  cout << "Copy initialized: " << b << endl;

  int c1(5); // direct initialization
  int c2{6};
  cout << "Direct initialized: " << c1 << " & " << c2 << endl;

  char e[8] = {'a', 'b', 'c', 'd'}; // aggregate initialization
  char f[8] = {"abcd"};
  cout << "e & f : " << e << " & " << f << endl;

  int g{}; // value initialization
  cout << "Value initialized: " << g << endl;

  /*
   * Initialization on Heap
   */
  char *h1 = new char[8]{};
  char *h2 = new char[8]{"Hello"};
  cout << "Heap: " << h1 << " & " << h2 << endl;
  return 0;
}
