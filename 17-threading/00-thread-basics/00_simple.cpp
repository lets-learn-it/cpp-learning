#include <iostream>
#include <thread>

void hello(int i) {
  std::cout << "hello from (function) " << i << std::endl;
}

void inc(int &i) {
  std::cout << "Getting reference: " << i << std::endl;
  i++;
}

class Hello {
  public:
    void operator()(int i) {
      std::cout << "hello from (class) " << i << std::endl;
    }
};

int main(int argc, char const *argv[]) {
  int i = 0;
  Hello h1;
  std::thread thr1(hello, 1), thr2(h1, 2), thr3(inc, std::ref(i));

  std::thread thr4([](int i) {
    std::cout << "hello from (lambda) " << i << std::endl;
  }, 3);

  // wait for those threads
  thr1.join(); thr2.join(); thr3.join(); thr4.join();

  std::cout << "Value of i: " << i << std::endl;

  return 0;
}
