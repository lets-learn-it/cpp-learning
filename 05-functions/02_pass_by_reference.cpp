#include <iostream>
using namespace std;

void increment(int &);
void increment(int *);

int main() {
  int a = 10;

  printf("Initial Value: %d\n", a);

  // send address of a
  increment(&a);
  printf("After increment: %d\n", a);

  // create int type pointer
  int* b = &a;
  increment(b);
  printf("b pointing to: %d & value of a: %d\n", *b, a);
  return 0;
}

void increment(int &a) {
  cout << "Inside increment(int &a)\n";
  a = a + 1;
}

void increment(int *a) {
  cout << "Inside increment(int *a)\n";
  *a = *a + 1;
}