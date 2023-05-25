#include <iostream>
#include <string>

typedef struct person {
  std::string name;
  int age;
} Person;

void print(Person &p) {
  std::cout << "Person [ " << &p << " ] { name: '" << p.name << "', age: " << p.age << " }\n";
}

int main(int argc, char const *argv[]) {
  struct person p1;
  Person p2;

  // assign values to p1 & p2
  p1.name = "P1"; p1.age = 10;
  print(p1); print(p2);

  // initialize struct while creating
  Person p3 {
    name: "P3",
    age: 55
  };

  Person p4 {"P4", 66};
  print(p3); print(p4);

  Person p5 = {
    name: "P5",
    age: 55
  };

  Person p6 = {"P6", 66};
  print(p5); print(p6);

  return 0;
}
