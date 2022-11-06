#include <iostream>
using namespace std;

int main() {
  int *p1 = new int;     // initialize to 0
  int *p2 = new int(50); // initialize to 50

  cout << "P1 Value at allocated location: " << *p1 << " & Address of location: " << p1 << endl;
  cout << "P2 Value at allocated location: " << *p2 << " & Address of location: " << p2 << endl;

  *p1 = 10;
  cout << "P1 Value at allocated location: " << *p1 << " & Address of location: " << p1 << endl;

  delete p1;
  delete p2;
  cout << "P1 Value at allocated location: " << *p1 << " & Address of location: " << p1 << endl;
  
  return 0;
}