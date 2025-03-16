#include<bits/stdc++.h>
using namespace std;

void print_1toN(int n) {
  // base case
  if (n == 0) return;

  // hypothesis
  print_1toN(n-1);

  // induction
  cout << n << " ";
}

void print_Nto1(int n) {
  if (n == 0) return;

  cout << n << " ";
  print_Nto1(n-1);
}

int main(int argc, char const *argv[]) {
  print_1toN(21);

  cout << endl;

  print_Nto1(21);
  return 0;
}
