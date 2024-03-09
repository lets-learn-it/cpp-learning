#include <iostream>
/*
 * https://en.wikipedia.org/wiki/Type_punning
 * https://en.cppreference.com/w/cpp/language/reinterpret_cast
 */

int main() {
  int x = 32;
  std::cout << "Address of x: " << &x << " value: " << x << std::endl;

  // y will take first 4 bytes from x
  double& y = *(double*)&x;
  std::cout << "Address of y: " << &y << " value: " << y << std::endl;

  // z will copy first 4 bytes from x + next 4 bytes next to x
  // to variable as we are not using reference
  double z = *(double*)&x;
  std::cout << "Address of z: " << &z << " value: " << z << std::endl;

  // reinterpret_cast
  double& w = *reinterpret_cast<double*>(&x);
  std::cout << "Address of w: " << &w << " value: " << w << std::endl;

  return 0;
}