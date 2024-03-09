#include <iostream>

/*
 * - Converts between types with different cv (const & volatile) qualification
 * - It allows programmers to temporarily remove constancy of an object & make modifications.
 *      const_cast<target_type>(expression)
 * https://en.cppreference.com/w/cpp/language/const_cast
 */


int main() {
  const int num = 5;
  const int* num_p = &num;

  int* nump = const_cast<int*>(num_p);
  *nump = 15;

  // num is 5 & location of num has 15
  // because compiler considered num as 5 & put 5 at each place at compile time
  std::cout << num << " " << *nump << " " << *num_p << std::endl;

  return 0;
}