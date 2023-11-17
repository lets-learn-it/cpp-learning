#include <iostream>
#include <string>
#include <cstdint>
#include <cstdio>
#include <typeinfo>

typedef double f64;
typedef float f32;

template <typename T>
T maxOf( const T &a, const T &b ) {
  std::cout << "Type of T: " << typeid(a).name() << std::endl;
  return ( a > b ? a : b );
}

int main() {
  int32_t a1 = 23, b1 = 45;
  f32 a2 = 66.57, b2 = 23.45;
  f64 a3 = 66.57, b3 = 23.45;

  // compiler will create 2 functions at compile time to handle below calls.
  printf("Max of %d & %d = %d\n", a1, b1, maxOf<int32_t>(a1, b1));
  printf("Max of %f & %f = %f\n", a2, b2, maxOf<f32>(a2, b2));

  // no need to add template parameters. compiler can understand.
  printf("Max of %d & %d = %d\n", a1, b1, maxOf(a1, b1));
  printf("Max of %f & %f = %f\n", a3, b3, maxOf(a3, b3));

  return 0;
}