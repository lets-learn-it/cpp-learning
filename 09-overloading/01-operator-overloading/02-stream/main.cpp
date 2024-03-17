#include <iostream>

class Test {
private:
  int x;
public:
  Test(int x=0): x(x) {}

  friend std::istream& operator >> (std::istream& input, Test& obj);
  friend std::ostream& operator << (std::ostream& output, Test& obj);
};

std::istream& operator >> (std::istream& input, Test& obj) {
  input >> obj.x;
  return input;
}

std::ostream& operator << (std::ostream& output, Test& obj) {
  output << obj.x;
  return output;
}

int main() {
  Test t1(23);

  std::cout << t1;
  return 0;
}
