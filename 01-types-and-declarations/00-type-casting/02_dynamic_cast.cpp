#include <iostream>
#include <exception>

/*
 * - safely converts pointers & references to classes up, down, and sideways along the inheritance hierarchy
 * - It ensures type safety by performing a runtime check to verify the validity of the conversion.
 * - If conversion is not possible, it returns null pointer for pointer conversions or throws
 * a bad_cast exception for reference conversions.
 *      dynamic_cast<target_type>(expression)
 * https://en.cppreference.com/w/cpp/language/dynamic_cast
 */


class Animal {
public:
  virtual void speak() const {
    std::cout << "Animal speaks." << std::endl;
  }
};

class Cat: public Animal {
public:
  void speak() const override {
    std::cout << "Cat speaks." << std::endl;
  }
};

class Dog: public Animal {
public:
  void speak() const override {
    std::cout << "Dog speaks." << std::endl;
  }
};

int main() {
  Animal *a1 = new Dog();
  Animal *a2 = new Cat();

  // down cast for pointer
  Dog *dc = dynamic_cast<Dog*>(a1);
  if (dc != nullptr) dc->speak();

  Cat *cc = dynamic_cast<Cat*>(a1);   // will fail
  if (cc == nullptr) std::cout << "cast failed..\n";

  // down cast for reference
  try {
    Dog& dr = dynamic_cast<Dog&>(*a1);
    dr.speak();
  } catch(std::bad_cast e) {
    std::cout << e.what() << std::endl;
  }

  try {
    Dog& dr = dynamic_cast<Dog&>(*a2);
  } catch(std::bad_cast e) {
    std::cout << e.what() << std::endl;
  }

}