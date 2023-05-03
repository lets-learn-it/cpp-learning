#include <iostream>
using namespace std;

int main() {
  int a = 10;

  cout << "Value of a: " << a << " & address of a: " << &a << endl;

  // declare reference
  // it is just alias
  // references must be initialized
  int &p = a;

  // dereferencing not required
  // like we did for pointers *p
  cout << "Value of p: " << p << " & address of p: " << &p << endl;
  
  int x = 12;

  // it is not like pointer
  // this will change actual vairiable a
  p = x;
  cout << "Value of p: " << p << " & address of p: " << &p << endl;

  return 0;
}