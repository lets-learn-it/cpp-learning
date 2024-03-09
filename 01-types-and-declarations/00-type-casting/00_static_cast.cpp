#include <iostream>

/*
 * - Converts between types using a combination of implicit & user-defined conversions.
 * - It performs compile time type conversions & is used for explicit conversions that are considered safe by compiler
 *      static_cast<target_type>(expression)
 * https://en.cppreference.com/w/cpp/language/static_cast
 */

class B {
public:
  void hello() { std::cout << "I am B!\n"; }
};

class C : public B {
public:
  int c = 0;
  void hello() { std::cout << "I am C!" << c << std::endl; }
};

int main() {
  int num = 10;

  // convert int to double
  double numd = static_cast<double>(num);

  std::cout << typeid(numd).name() << " " << typeid(num).name() << std::endl;

  C c;
  B& br = c;

  br.hello();


  return 0;
}