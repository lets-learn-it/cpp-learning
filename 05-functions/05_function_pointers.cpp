#include <iostream>
using namespace std;

int get_sum(int a, int b) {
  return a + b;
}

int do_operation(int (*fun)(int, int), int a, int b) {
  return fun(a, b);
}

void iAMExiting() {
  cout << "Bye, bye..." << endl;
}

int main() {
  int (*a)(int, int) = get_sum;

  cout << a(3,4) << endl;

  cout << do_operation(a, 5, 6) << endl;

  /* 
   * c & cpp has atexit function
   * which takes function pointer and while exiting program, it will get invoked
   */
  atexit(iAMExiting);

  cout << "Registered atexit..." << endl;
  return 0;
}

