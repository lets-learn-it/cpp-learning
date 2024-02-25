#include <iostream>
#include <string>

template <typename T, int N>
class Array {
private:
  T m_Array[N];
public:
  int getLength() const { return N; }
  int getSize() const { return sizeof(m_Array); }

  // VIMP
  T operator[](int index) const { return m_Array[index]; }
  T& operator[](int index) { return m_Array[index]; }
};

int main() {
  Array<int, 5> a1;
  std::cout << a1.getSize() << " | " << a1.getLength() << std::endl;

  Array<double, 10> a2;
  std::cout << a2.getSize() << " | " << a2.getLength() << std::endl;

  // VIMP
  a2[1] = 5.66;
  std::cout << a2[1];
  return 0;
}