#include <iostream>

void callMe() {
  using namespace std;
  cout << "Thanks for calling...\n";
}

int main() {
  int a = 10;

  callMe();

  return 0;
}