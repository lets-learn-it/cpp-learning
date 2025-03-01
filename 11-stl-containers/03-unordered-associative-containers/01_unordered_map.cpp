#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

/*
 * Unordered set is a hash table based associative container that key value pairs.
 * Search, insertion, and removal have average constant-time complexity O(1). Worst case O(n)
 *
 * Internally, the keys are not sorted in any particular order, but organized into buckets.
 * Which bucket an key is placed into depends entirely on the hash of its value.
 * This allows fast access to individual elements, since once a hash is computed,
 * it refers to the exact bucket the element is placed into.
 *
 * custom hash function can be added
 * No ordering guarantee: elements are stored in an arbitrary order
 */

template<typename T1, typename T2>
void print_map(const char *message, unordered_map<T1, T2> &s) {
  cout << message << ": ";
  for(const auto& x : s) cout << "{ " << x.first << ": " << x.second << " } ";
  cout << endl;
}

int main() {
  unordered_map<string, int> cmap;

  // insert elements
  cmap.insert({"def", 14});
  cmap.insert({"abc", 4});

  cmap["abc"] += 1;
  cmap["xyz"] += 23;

  print_map("cmap map: ", cmap);

  // check if key exists
  if (cmap.find("abc") != cmap.end()) {
    cout << "abc exists" << endl;
  }

  if (cmap.count("pqr") > 0) {
    cout << "pqr exists" << endl;
  }

  // erasing
  cmap.erase("abc");   // exists
  cmap.erase("pqr");   // does not
  print_map("cmap after erase: ", cmap);
}