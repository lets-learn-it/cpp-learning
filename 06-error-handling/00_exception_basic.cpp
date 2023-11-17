#include<bits/stdc++.h>
using namespace std;

void deepException() {
  throw string("Deep Exception thrown");
}

void mightGoWrong() {
  bool error = true;
  deepException();
  if(error) {
      throw "error message";
  }
  if(error) {
      throw 8;
  }
}

int main() {
  try {
      mightGoWrong();
  } catch(int e) {
      cout << e;
  } catch(char const * e) {
      cout << e;
  } catch(string &e) {
      cout << e;
  }
  return 0;
}