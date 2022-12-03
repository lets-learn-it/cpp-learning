#include <iostream>
using namespace std;

int main() {
  cout << "Pls enter your name: ";
  char a[50];
  cin.getline(a, 50, '\n');
  cout << "Hello, " << a << endl;
  cout << "Pls enter your age: ";
  int age;
  cin >> age;
  return 0;
}