#include <iostream>
#include <string>
#include <utility>
using namespace std;

// print the pair
template<typename T1, typename T2>
void print_pair(const char *s, pair<T1, T2> p) {
  cout << s << ": (" << p.first << ", " << p.second << ")\n";
}

void message(const char *s, const int n) { cout << s << ": " << n << endl; } 

int main() {
  // initializer list
  pair<int, string> p1 = {3, "three"};
  print_pair("pair p1", p1);

  // default constructor
  pair<int, string> p2(34, "thirty-four");
  print_pair("pair p2", p2);

  // from make_pair
  pair<int, string> p3;
  p3 = make_pair(95, "ninety-five");
  print_pair("pair p3", p3);

  // comparison operators
  message("p1 == p2", p1 == p2);
  message("p1 < p2", p1 < p2);
  message("p1 < p3", p1 < p3);
  message("p1 > p2", p1 >p2);
  message("p1 > p3", p1 > p3);

  return 0;
}