#include <iostream>
using namespace std;

/*
 * https://stackoverflow.com/questions/57483/what-are-the-differences-between-a-pointer-variable-and-a-reference-variable
 *
 * 1. pointer can be reassigned, reference cannot. references must be bound at initialization.
 * 2. A pointer variable has its own identity: a distinct, visible memory address.
 *    the reference’s own address and size are invisible. Since the reference assumes the identity of
 *    the original variable in this way, it is convenient to think of a reference as another name
 *    for the same variable
 * 3. It is possible to create a pointer to a pointer, but not a pointer to a reference.
 * 4. A pointer can be assigned nullptr, whereas a reference must be bound to an existing object.
 * 5. A pointer needs to be dereferenced with * to access the object it points to, whereas a reference can be used directly. A pointer to a class/struct uses -> to access its members whereas a reference uses a .
 *
 */

// pass by value
void swap(int , int );

// pass by address
void swap(int *, int *);

// pass by reference
void swapRef(int &, int &);

int main() {
  int x = 5, y = 10;

  cout << "(x, y) = (" << x << ", " << y << ")\n";

  swap(x, y);
  cout << "(x, y) = (" << x << ", " << y << ")\n";

  swap(&x, &y);
  cout << "(x, y) = (" << x << ", " << y << ")\n";

  swapRef(x, y);
  cout << "(x, y) = (" << x << ", " << y << ")\n";

  return 0;
}

void swap(int x, int y) {
  int temp = x;
  x = y;
  y = temp;
}

void swap(int *x, int *y) {
  // in case of pointers, we need to check for nullptr
  if ( x == nullptr || y == nullptr ) return;
  int temp = *x;
  *x = *y;
  *y = temp;
}

void swapRef(int &x, int &y) {
  int temp = x;
  x = y;
  y = temp;
}