#include <iostream>
#include <memory>

std::weak_ptr<int> wp;

void observe() {
  std::cout << "wp.use_count() == " << wp.use_count() << std::endl;
  if (wp.expired()) std::cout << "weak pointer wp is expired\n";
  else std::cout << "weak pointer wp is available\n";
}

int main(int argc, char const *argv[]) {
  {
    std::shared_ptr<int> p = std::make_shared<int>();
    wp = p;

    observe();
  }

  observe();
  
  return 0;
}
