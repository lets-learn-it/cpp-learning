#include <iostream>
using namespace std;

template <typename T>
void printa(T *a, int n) {
  for(int i=0;i<n;i++) {
    cout << *(a+i) << " ";
  }
  cout << endl;
}

int main() {
  int *p1 = new int[10];
  printa(p1, 10);

  delete []p1;
  return 0;
}