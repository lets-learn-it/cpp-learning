#include <iostream>

/*
 * - Converts between types by reinterpreting the underlying bit pattern
 * - It does not perform any check whether the pointer converted is of the same type of not
 *      reinterpret_cast<target_type>(expression)
 * https://en.cppreference.com/w/cpp/language/reinterpret_cast
 */

class Dog {
public:
  int age;
  Dog(int age): age(age){}
  void dog_age() { std::cout << this->age << std::endl;}
};

class Cat {
public:
  int age;
  Cat(int age): age(age){}
  void cat_age() { std::cout << this->age << std::endl;}
};

struct demo {
  int a;
  char b;
  bool c;
};

int main() {
  Cat c(4);

  // how the hell it is able to cast?
  // methods are attached with class & data is attached to object
  // When we call method like object.method() means
  // class::method(object *this, ...)
  Dog *d = reinterpret_cast<Dog*>(&c);
  d->dog_age();

  struct demo sd{12, 'c', true};

  int *di = reinterpret_cast<int*>(&sd);
  std::cout << *di << std::endl;

  return 0;
}