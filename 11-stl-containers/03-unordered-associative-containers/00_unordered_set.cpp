#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

/*
 * Unordered set is an associative container that contains a set of unique objects of type Key.
 * Search, insertion, and removal have average constant-time complexity
 *
 * Internally, the elements are not sorted in any particular order, but organized into buckets.
 * Which bucket an element is placed into depends entirely on the hash of its value.
 * This allows fast access to individual elements, since once a hash is computed,
 * it refers to the exact bucket the element is placed into.
 *
 * Container elements may not be modified (even by non const iterators)
 * since modification could change an element's hash and corrupt the container.
 */

template<typename T>
void print_set(const char *message, T &s) {
  cout << message << ": ";
  for(auto x : s) cout << x << " ";
  cout << endl;
}

int main() {
  unordered_set<string> set1 = {"one", "two", "three", "four"};
  print_set("set1", set1);

  set1.insert("ten");
  set1.insert("four"); // will be single "four" present
  print_set("inserted ten & four", set1);

  // find erase element three
  unordered_set<string>::iterator it = set1.find("three");
  if(it != set1.end()) {
    cout << "found in set. erasing...\n";
    set1.erase(it);
  }

  print_set("After erase", set1);

  // erase if present
  set1.erase("four");
  set1.erase("eleven");

  print_set("After another erase: ", set1);

  return 0;
}