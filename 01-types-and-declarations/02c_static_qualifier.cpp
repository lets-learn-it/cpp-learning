#include <iostream>
/*
 * static variable in function
 * When a variable is declared as static, space for it gets allocated for the lifetime of the program.
 * Even if the function is called multiple times, space for static variable is allocated only once and
 * the value of variable in the previous call gets carried through the next function call.
 *
 * static variable out of function / static function (not in class)
 * https://stackoverflow.com/questions/558122/what-is-a-static-function-in-c
 * static functions/variables are only visible to other functions in same file/translation unit.
 */

// build : g++ 02c_static_qualifier.cpp 02c_static.cpp

// if you remove static, you will get an error
// error: ld returned 1 exit status
static int var = 5;

static int my_num() {
  return 6;
}

int next_number() {
  static int num = 0;
  return num++;
}

int main() {
  std::cout << next_number() << std::endl;
  std::cout << next_number() << std::endl;
}
