#include <iostream>
#include <memory>

class Entity {
private:
  int a;
public:
  Entity (int num) {
    this->a = num;
    std::cout << "Creating Object " << a << std::endl;
  }
  ~Entity () {
    std::cout << "Destroying Object " << this->a << std::endl;
  }
};

// passing by value
void func(std::unique_ptr<Entity> ptr) {
  std::cout << "Inside func" << std::endl;

  // Entity will get destroyed
}

// passing by reference
void funcRef(std::unique_ptr<Entity> &ptr) {

}

int main(int argc, char const *argv[]) {

  std::unique_ptr<Entity> i = std::make_unique<Entity>(1);
  std::unique_ptr<Entity> j = std::make_unique<Entity>(2);

  func(std::move(i));
  // check if stored pointer is nullptr
  if (i.get() == nullptr) std::cout << "ptr i is not valid" << std::endl;

  funcRef(j);
  // check if associated managed object is available
  if (j) std::cout << "ptr j is valid" << std::endl;

  return 0;
}
