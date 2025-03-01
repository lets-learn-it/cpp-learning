#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
 * The elements are stored contiguously, which means that elements can be accessed
 * not only through iterators, but also using offsets to regular pointers to elements.
 *
 * The storage of the vector is handled automatically, being expanded as needed.
 * Vectors usually occupy more space than static arrays, because more memory is allocated to handle future growth.
 *
 * The total amount of allocated memory can be queried using capacity() function.
 * Extra memory can be returned to the system via a call to shrink_to_fit(). (since C++11)
 *
 * Reallocations are usually costly operations in terms of performance.
 * The reserve() function can be used to eliminate reallocations if the number of elements is known beforehand.
 *
 * Complexity/efficiency
 * Random access - constant O(1)
 * Insertion or removal of elements at the end - amortized constant O(1)
 * Insertion or removal of elements - linear in the distance to the end of the vector O(n)
 */

// print elements of vector
template<typename T>
void printv(vector<T> &v) {
  for(T &i : v) cout << i << " ";
  cout << endl;
}

void message(const char *s) { cout << s << endl; }
void message(const char *s, const int n) { cout << s << ": " << n << endl; }

int main() {
  vector<int> v1 = {1,2,3,4,5,6,7,8,9};
  cout << "Vector v1: ";
  printv(v1);

  // info
  message("size of v1", (int) v1.size()); // retuns size_t
  message("front of v1", v1.front());
  message("back of v1", v1.back());
  message("capacity of v1", v1.capacity());

  // index
  message("element at 5", v1[5]);
  message("element at 5", v1.at(5));

  // insert
  printf("insert 42 at begin + 5: ");
  v1.insert(v1.begin() + 5, 42);
  printv(v1);

  printf("push_back 56: ");
  v1.push_back(56);
  printv(v1);

  // erase
  printf("erase at begin + 5: ");
  v1.erase(v1.begin() + 5);
  printv(v1);

  printf("pop_back: ");
  v1.pop_back();
  printv(v1);

  message("size of v1 after erase", v1.size());
  message("capacity of v1 after erase", v1.capacity());

  // check empty
  printf("Is vector empty: ");
  vector<int> vx = {1,2,3};
  while(!vx.empty()) {
    printv(vx);
    vx.pop_back();
  }

  // clear
  vx.insert(vx.begin(), {1,2,3,4});
  printf("vx before clear: ");
  printv(vx);
  vx.clear();
  printf("vx after clear: ");
  printv(vx);

  // from C-array
  constexpr size_t size = 10;
  int ia[size] = {1,2,3,4,5,6,7,8,9,10};
  printf("Vector from c-array: ");
  vector<int> v2(ia, ia + size);
  printv(v2);

  // filled with strings
  printf("string vector: ");
  vector<string> v3(5, "string");
  printv(v3);

  // copy constructor
  printf("vector copied from vector: ");
  vector<string> v4(v3);
  printv(v4);

  // moving elements from one vector to another
  printf("vector v5: ");
  vector<string> v5(std::move(v4));
  printv(v5);
  message("size of v4", v4.size());
  message("size of v5", v5.size());

  return 0;
}
