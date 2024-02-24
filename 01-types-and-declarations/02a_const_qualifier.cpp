#include <iostream>
using namespace std;

/*
 *
 * const
 * - creates variable that is constant
 * - value can't be modified
 * - attempt to modify will cause compilation error
 * - qualified to declaration, but always needs an initializer
 * - good alternatives to C macros
 * - commonly used with references (function should not modify args)
 */

const float PI = 3.14159f;

float area_of_circle(float radius) {
  // pi = 3; // expression must be a modifiable lvalue
  return PI * radius * radius;
}

void print(const int *ptr) {
  // function cant change value pointed by ptr
  // *ptr = 12;
  cout << "ptr: " << *ptr << endl;
}

void print(const int &ptr) {
  // ptr = 12;
  cout << "ptr: " << ptr << endl;
}

int main() {
  int radius = 2;

  cout << "A(r=" << radius << ") = " << area_of_circle(radius) << endl;

  // const & pointer
  const int CHUNCK_SIZE = 512;
  // ptr should be const
  const int * ptr1 = &CHUNCK_SIZE; // you can change ptr but not value pointing ptr

  // const pointer
  int x = 10;
  int * const ptr2 = &x; // you can change value of x but ptr2 cant point to any other location
  // ptr2 = &CHUNCK_SIZE; // not allowed

  *ptr2 = 12;
  cout << "Value of x: " << x << endl;

  // passing const
  print(&x);
  print(x);
  return 0;
}
