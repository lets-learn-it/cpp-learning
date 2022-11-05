#include<iostream>
#include<array>
#include<algorithm>
#include<string>

template<class T, std::size_t SIZE>
void printa(const char *s, std::array<T, SIZE> &arr) {
  std::cout << s << ": ";
  for(T a: arr) {
    std::cout << a << " ";
  }
  std::cout << std::endl;
}

template<class T>
void message(const char *s, const T &v) { std::cout << s << ": " << v << std::endl; }

int main() {
  // basic array
  std::array<int, 4> a1 = {1,2,3,4};

  a1[0] = 10;
  a1[1] = 8;
  a1[3] = 44;

  printa("array a1", a1);

  std::sort(a1.begin(), a1.end());

  printa("a1 after sort", a1);

  // string array
  std::array<std::string, 3> a2;

  a2 = {"One", "two", "three"};

  printa("string array a2", a2);

  // check size
  message("size of a1", a1.size());
  message("size of a2", a2.size());

  // access elements
  message("3rd element of a1", a1[2]);
  message("2nd element of a2", a2[1]);
  message("3rd element of a1", a1.at(2));
  message("2nd element of a2", a2.at(1));
  
  // direct access data
  int *ip1 = a1.data();
  for(size_t i=0;i<a1.size(); i++)
    std::cout << *ip1++ << " ";

  
  return 0;
}