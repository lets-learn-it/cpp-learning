#include <iostream>
using namespace std;

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