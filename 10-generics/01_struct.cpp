#include <iostream>
#include <string>
#include <cstdint>
#include <cstdio>
#include <typeinfo>

typedef double f64;
typedef float f32;

template <typename T1, typename T2>
struct Pair {
  T1 first;
  T2 second;

  // constructor
  Pair(const T1& f, const T2& s): first(f), second(s) {}

  void print() const {
    std::cout << "{ " << first << ", " << second << " }\n";
  }
};

int main() {
  Pair<int32_t, f32> p1(100, 3.14);

  p1.print();

  return 0;
}