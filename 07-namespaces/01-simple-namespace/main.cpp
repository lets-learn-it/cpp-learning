#include <iostream>
#include "namespace1.cpp"
#include "namespace2.cpp"
using namespace std;

int main() {
  cout << "Value for one::display: " << one::display() << endl;
  cout << "Value for two::display: " << two::display() << endl;

  return 0;
}