#include <iostream>
#include "Integer.hpp"
using namespace std;

int main(int argc, char const *argv[]) {
  Integer a1(34);
  Integer a2 = Integer(76);

  // a2 will be passed as argument
  // to a1 method.
  Integer a3 = a1 + a2;

  cout << a3.get_number() << endl;
  return 0;
}
