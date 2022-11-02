#include <iostream>
#include "namespace1.cpp"
using namespace std;

namespace one = thisIsNamespaceOne;
namespace two = one::thisIsNamespaceTwo;

int main() {
  cout << one::display() << endl;
  cout << two::display();

  return 0;
}