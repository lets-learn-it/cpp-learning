#include <iostream>
using namespace std;

int main() {
  int choice = 1;

  switch (choice) {
  case 1:
    cout << "You chose 1\n";
    break;
  case 2:
    cout <<"You chose 2\n";
    break;
  default:
    cout << "You chose something else\n";
    break;
  }
  
  return 0;
}