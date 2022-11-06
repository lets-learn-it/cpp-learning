#include <iostream>
using namespace std;

// need to allocate frame on stack
int squarefunc(int n) { return n * n; }

inline int squareinline(int n) { return n * n; }

#define squaremacro(n) n*n

int main() {
  int n = 3;

  cout << "sqaurefunc: " << squarefunc(n+1) << endl;

  // should be 16 but n+1*1+n
  // compile time substitution
  cout << "sqauremacro: " << squaremacro(n+1) << endl;

  // inline function
  /* 
   * Only a request to compiler to not create function (compiler will decide)
   *
   * Certain functions may not be inlined
   * - large functions
   * - functions having too many conditional statements
   * - recursive functions
   * - functions invoked through pointers
   */
  cout << "sqaureinline: " << squareinline(n+1) << endl;

  return 0;
}