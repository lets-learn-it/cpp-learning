#include <iostream>
#include <memory>
#include <thread>

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
 * The reference count maintained by std::shared_ptr is thread-safe, 
 * which means that multiple threads can safely increment and 
 * decrement the reference count without any race conditions or data races. 
 * However, you still need to be careful about how you access the managed object itself.
 */

void func(std::shared_ptr<Entity> ptr) {
  auto p = ptr;  // this operation is thread safe
  std::cout << "Thread Id: " << std::this_thread::get_id() << std::endl;
  std::cout << "use_count of ptr: " << p.use_count() << std::endl;
}

int main(int argc, char const *argv[]) {
  std::shared_ptr<Entity> i = std::make_shared<Entity>(1);

  std::thread t1{func, i}, t2{func, i}, t3{func, i};

  t1.join(); t2.join(); t3.join();
  return 0;
}
