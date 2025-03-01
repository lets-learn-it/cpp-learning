#include <iostream>
#include <string>
#include <tuple>
#include <map>
using namespace std;

tuple<int, string> user(int age, string s) {
  return make_tuple(age, s);
}

tuple<int, string> employee(int age, string s) {
  return tuple<int, string>{age, s};
}

int main() {
  tuple<int, string> t1 = user(26, "parikshit");
  auto t2 = user(35, "xyz");
  auto t3 = employee(34, "PQR");

  cout << get<0>(t1) << " " << get<1>(t1) << endl;

  map<tuple<int, string>, int> m;

  m[t1] += 1;
  m[t2] += 1;
  m[t1] += 1;
  m[t3] += 1;

  for (auto& x: m) {
    cout << "(" << get<0>(x.first) << ", " << get<1>(x.first) << ") = " << x.second << endl;
  }
  return 0;
}