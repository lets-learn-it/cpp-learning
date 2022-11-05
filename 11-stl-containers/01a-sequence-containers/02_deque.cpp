#include <iostream>
#include <deque>
#include <string>
using namespace std;

/* 
 * std::deque (double-ended queue) is an indexed sequence container that 
 * allows fast insertion and deletion at both its beginning and its end.
 * 
 * the elements of a deque are not stored contiguously: typical implementations
 * use a sequence of individually allocated fixed-size arrays, with additional bookkeeping,
 * which means indexed access to deque must perform two pointer dereferences,
 * compared to vector's indexed access which performs only one.
 * 
 * Expansion of a deque is cheaper than the expansion of a std::vector because
 * it does not involve copying of the existing elements to a new memory location.
 * 
 * On the other hand, deques typically have large minimal memory cost;
 * a deque holding just one element has to allocate its full internal array
 * (e.g. 8 times the object size on 64-bit libstdc++; 16 times the object size or 4096 bytes,
 * whichever is larger, on 64-bit libc++).
 * 
 * Complexity/efficiency
 * Random access - constant O(1)
 * Insertion or removal of elements at the end or beginning - constant O(1)
 * Insertion or removal of elements - linear O(n)
 * 
 */

// print deque
template <typename T>
void printdeq(const char *s, T &d) {
  cout << s << ": ";
  if (d.empty()) return;
  for (auto v : d) cout << v << " ";
  cout << endl;
}

int main() {
  deque<string> d1 = {"one", "two", "three"};
  printdeq("deque d1", d1);

  d1.push_back("four");
  d1.push_back("five");
  printdeq("push_back d1", d1);

  d1.push_front("zero");
  printdeq("push_front d1", d1);

  cout << "d1 front: " << d1.front() << endl;
  cout << "d1 back: " << d1.back() << endl;

  d1.pop_front();
  d1.pop_back();
  printdeq("after poping d1", d1);

  // info
  cout << "size of d1: " << d1.size() << endl;

  return 0;
}