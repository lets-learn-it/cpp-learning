#include <iostream>
using namespace std;

void toh(char s, char d, char h, int n) {
  if (n==0) {
    return;
  }

  toh(s, h, d, n-1);
  cout << "move disk " << n << " from " << s << " to " << d << endl;
  toh(h, d, s, n-1);
}

int main() {
  char source = 'S';
  char dest = 'D';
  char helper = 'H';
  toh(source, dest, helper, 10);
}