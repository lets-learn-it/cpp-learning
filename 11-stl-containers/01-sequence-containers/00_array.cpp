#include<iostream>
#include<array>
#include<algorithm>
#include<string>

template<class T, std::size_t SIZE>
void printArray(std::array<T, SIZE> &arr) {
  for(auto a: arr) {
    std::cout << a << " ";
  }
  std::cout << std::endl;
}

int main() {
  // basic array
  std::array<int, 4> a1;

  a1[0] = 10;
  a1[1] = 8;
  a1[3] = 44;

  printArray(a1);

  std::sort(a1.begin(), a1.end());

  printArray(a1);

  // string array
  std::array<std::string, 3> a2;

  a2[0] = "One";
  a2[1] = "Two";

  printArray(a2);
  
  return 0;
}