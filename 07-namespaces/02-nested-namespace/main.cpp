#include <iostream>
#include "namespace1.cpp"
using namespace std;

int main() {
  cout << "Value from one::two::display() = " << one::two::display() << endl;
  cout << "Value from one::display() = " << one::display() << endl;

  return 0;
}