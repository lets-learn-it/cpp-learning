#include <iostream>
#include <string>
using namespace std;

template <typename T>
T maxOf( const T &a, const T &b) {
  return ( a > b ? a : b );
}

int main() {
  int a1 = 23, b1 = 45;
  double a2 = 66.57, b2 = 23.45;

  // compiler will create 2 functions at compile time to handle below calls.
  cout << "Max of " << a1 << " & " << b1 << " = " << maxOf<int>(a1, b1) << endl;
  cout << "Max of " << a2 << " & " << b2 << " = " << maxOf<double>(a2, b2) << endl;

  return 0;
}