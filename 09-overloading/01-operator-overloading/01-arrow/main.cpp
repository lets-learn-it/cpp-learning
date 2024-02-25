#include <iostream>
#include <string>

class Entity {
private:
  int x;
public:
  void PrintConst() const {
    std::cout << "Hello " << x << std::endl;
  }

  void Print() {
    std::cout << "Hello " << x << std::endl;
  }
};

class ScopedPtr {
private:
  Entity *m_Obj;
public:
  ScopedPtr(Entity *entity)
    : m_Obj(entity) {}

  ~ScopedPtr() {
    delete m_Obj;
  }

  // arrow operator overloading
  Entity* operator->() {
    std::cout << "not const" << std::endl;
    return m_Obj;
  }

  const Entity* operator->() const {
    std::cout << "const" << std::endl;
    return m_Obj;
  }
};

int main() {
  ScopedPtr ptr1 = new Entity();
  ptr1->Print();

  const ScopedPtr ptr2 = new Entity();
  ptr2->PrintConst();

  return 0;
}