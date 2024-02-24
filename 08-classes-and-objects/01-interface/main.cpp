#include <iostream>

class Animal {
public:
  // = 0 forces child classes to implement this method
  // you can create object of Animal
  virtual void run() const = 0;
};

class Human : public Animal {
private:
  std::string name;
public:
  Human(std::string n) {
    this->name = n;
  }

  // override infers this method is overriding a virtual method (not required)
  // const: method guarantees not to modify the state of the object
  void run() const override {
    std::cout << "Human running: " << this->name << std::endl;
  }
};

class Tiger : public Animal {
public:
  void run() const override {
    std::cout << "Tiger running.\n";
  }
};

void make_run1(Animal *animal) {
  animal->run();
}

void make_run2(Animal &animal) {
  animal.run();
}

int main() {
  Human h = Human("Parikshit");
  Tiger t = Tiger();

  make_run1(&h);
  make_run2(t);

  return 0;
}
