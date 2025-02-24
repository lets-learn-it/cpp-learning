#include <iostream>
#include "heap.hpp"

int main() {
  Heap<int> h1;
  h1.push(23);
  h1.push(45);
  h1.push(21);
  h1.push(56);
  h1.push(1);

  while(!h1.empty()) {
    std::cout << h1.top() << " ";
    h1.pop();
  }

  std::cout << std::endl;

  Heap<double> h2;
  h2.push(23.5);
  h2.push(45.7);
  h2.push(21.1);
  h2.push(56.6);
  h2.push(1);

  while(!h2.empty()) {
    std::cout << h2.top() << " ";
    h2.pop();
  }
}