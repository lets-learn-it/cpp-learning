#include <iostream>
#include "namespace1.cpp"
using namespace std;

int main() {
  cout << one::displayOne() << endl;
  cout << display();

  return 0;
}