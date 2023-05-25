#include <iostream>
#include <string>

// no need of typedef
struct Person {
  std::string name;
  int age;

  // Constructor
  Person(const std::string& n, const int& a) : name(n), age(a) {
    std::cout << "Constructing Person " << name << std::endl;
  }

  // destructor
  ~Person() {
    std::cout << "Destructing Person " << name << std::endl;
  }

  // member function
  void print() {
    std::cout << "Person [ " << this << " ] { name: '" << name << "', age: " << age << " }\n";
  }
};



int main(int argc, char const *argv[]) {
  Person p1("P1", 30);
  p1.print();

  Person *p2 = new Person("P2", 25);
  p2->print();
  delete p2;

  return 0;
}
