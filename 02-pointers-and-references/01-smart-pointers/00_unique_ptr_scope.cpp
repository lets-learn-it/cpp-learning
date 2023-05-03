#include <iostream>
#include <memory>

/* 
 * std::unique_ptr is a smart pointer that owns and manages another object through 
 * a pointer and disposes of that object when the unique_ptr goes out of scope.
 */

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

/* 
 * Function will create pointer x but as soon as it returns,
 * unique pointer memory is released.
 */
void func() {
  std::unique_ptr<Entity> x(new Entity(8));
}

int main(int argc, char const *argv[]) {
  /* 
   * Scope in blocks & creation and delection of underlying objects
   */
  {
    std::unique_ptr<Entity> i(new Entity(1));
    {
      std::unique_ptr<Entity> j(new Entity(2));
      // i = j;  // Not possible
    }
  }
  
  /* 
   * reset can be used to manually release memory.
   * once memory is released, k.get() returns nullptr
   */
  std::unique_ptr<Entity> k{new Entity(3)};

  // lets reset k
  k.reset();

  /* 
   * reset can be used to point another memory.
   * old memory will be released.
   */
  std::unique_ptr<Entity> l{new Entity(4)};
  l.reset(new Entity(5));


  /*
   * if we dont want to destroy object after scope
   * we can release it from unique_ptr
   */
  std::unique_ptr<Entity> m{new Entity(6)};
  // there will be no destruction of m
  m.release();

  /*
   * No need to free j because after completion of main, it will
   * automatically gets deleted.
   */
  std::unique_ptr<Entity> j{new Entity(7)};

  func();

  return 0;
}
