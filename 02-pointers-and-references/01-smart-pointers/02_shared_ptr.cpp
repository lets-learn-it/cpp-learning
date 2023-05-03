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

int main(int argc, char const *argv[]) {
  std::shared_ptr<Entity> i = std::make_shared<Entity>(1);
  
  {
    // create copy of i
    auto j = i;

    // check how many pointers are pointing to entity above created
    std::cout << "Number of pointer pointing entity: " << i.use_count() << std::endl;
  }

  std::cout << "Number of pointer pointing entity: " << i.use_count() << std::endl;

  auto k = i;
  std::cout << "Number of pointer pointing entity: " << i.use_count() << std::endl;

  // reset k
  k.reset();

  std::cout << "Number of pointer pointing entity: " << i.use_count() << std::endl;

  return 0;
}
