#include <iostream>
#include <forward_list>

#define DEBUG(x) std::cout << ">> " << #x << ": " << x << std::endl;

/*
 * std::forward_list is a container that implemented as a singly-linked list.
 * It support fast insertion & removal of elements from anywhere but fast random access not supported.
 * space efficient than std::list if bidirectional iteration is not needed.
 */

template<typename T>
void printl(const char *s, std::forward_list<T> &l) {
  std::cout << s << ": ";
  for(T &i : l) std::cout << i << " ";
  std::cout << std::endl;
}

int main() {
  std::forward_list<int> a1 = {1,2,3,4};
  std::forward_list<int> a2 {1,2,3,4,5,6};
  std::forward_list<int> a3;
  a3 = {6,7,9,12,11,50,40};

  // print forward_list
  printl("a1", a1);
  printl("a2",a2);
  printl("a3", a3);

  // get front of forward_list
  int f = a1.front();
  DEBUG(f);

  // remove first element
  a1.pop_front();
  printl("a1", a1);

  // push to front
  a1.push_front(22);
  printl("a1", a1);

  // iterator
  std::forward_list<int>::iterator start = a1.begin();
  for (;start != a1.end(); start++) {
    std::cout << *start << " ";
  }
  std::cout << std::endl;

  // sort
  a3.sort();
  printl("a3 (sorted)", a3);

  // merge sorted forward_list
  a1.merge(a3);
  printl("a1 + a3", a1);

  // erasing elements
  a1.erase_after(a1.before_begin());    // removes first element
  printl("a1 (removed first)", a1);

  auto fi = std::next(a1.begin());
  auto la = std::next(fi, 3);

  a1.erase_after(fi, la);
  printl("a1 (remove multiple)", a1);

  return 0;
}