#include <iostream>

class Integer {
private:
  int number;
public:
  Integer(int number);
  ~Integer();
  int get_number();

  // overload + operator
  Integer operator + (Integer a1);
};

Integer::Integer(int number) {
  this->number = number;
  std::cout << "Inside constructor" << std::endl;
}

Integer::~Integer() {
  std::cout << "Inside destructor" << std::endl;
}

int Integer::get_number() {
  return number;
}

Integer Integer::operator+(Integer a1) {
  std::cout << "Got value " << a1.get_number() << std::endl;
  return Integer(this->get_number() + a1.get_number());
}