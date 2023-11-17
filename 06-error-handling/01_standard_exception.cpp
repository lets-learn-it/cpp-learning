#include<bits/stdc++.h>
using namespace std;

class CanGoWrong {
public:
  CanGoWrong() {
    char *pMemory = new char[999999999999999];
    delete [] pMemory;
  }
};

int main(){
  try {
  CanGoWrong wrong;
  } catch(bad_alloc &e) {
      cout << e.what();
  }

  // bad_alloc is child class of exception
  // so we can use exception and what is virtual method in exception class

  cout << "\nstill running";
  return 0;
}
