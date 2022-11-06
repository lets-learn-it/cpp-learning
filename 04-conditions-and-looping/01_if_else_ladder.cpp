#include <iostream>
using namespace std;

int main() {
  int marks = 88;

  if(marks >= 80) {
    cout << "You got first class...\n";
  } else if(marks >= 40) {
    cout << "You Passed...\n";
  } else {
    cout << "You Failed..." << endl;
  }
  return 0;
}