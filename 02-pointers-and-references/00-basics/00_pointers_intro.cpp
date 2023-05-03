#include <iostream>
using namespace std;

int main() {
  int a = 10;

  cout << "Value of a: " << a << " & address of a: " << &a << endl;

  // declare pointer
  // pointer is like a variable which is holding memory address.
  // below, p can hold address of integer variable
  int *p;

  // let p hold address of a
  p = &a;
  cout << "Value of p: " << p << " & address of p: " << &p << endl;

  // accessing actual a using pointer p
  // * is dereference operator
  // it will visit address pointed by pointer
  *p = 12;
  cout << "Value of a: " << a << " & address of a: " << &a << endl;

  // size of pointer
  cout << "size of pointer: " << sizeof(p) << endl;
  
  return 0;
}