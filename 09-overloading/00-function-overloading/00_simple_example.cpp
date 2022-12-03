#include <iostream>
using namespace std;

/* 
 * static polymorphism
 */

int add(int a, int b) { return a + b; }
float add(float a, float b) { return a + b; }

int main() {
  int a1 = 10, b1 = 15;
  float a2 = 14.5f, b2 = 45.7f;

  cout << "sum: " << add(a1, b1) << endl;
  cout << "sum: " << add(a2, b2) << endl;

  return 0;
}