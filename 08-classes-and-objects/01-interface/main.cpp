#include <iostream>

class Animal {
public:
  virtual void run() const = 0;
};

class Human : public Animal {
private:
  std::string name;
public:
  Human(std::string n) {
    this->name = n;
  }

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






