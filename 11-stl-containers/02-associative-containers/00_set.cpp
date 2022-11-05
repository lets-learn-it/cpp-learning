#include <iostream>
#include <string>
#include <set>
#include <unordered_set>
using namespace std;

/* 
 * std::set is an associative container that contains a sorted set of unique objects of type Key.
 * Sorting is done using the key comparison function Compare. 
 * Search, removal, and insertion operations have logarithmic complexity. 
 * Sets are usually implemented as red-black trees.
 *
 */

template<typename T>
void print_set(const char *message, T &s) {
  cout << message << ": ";
  for(auto x : s) cout << x << " ";
  cout << endl;
}

int main() {
  set<string> set1 = {"one", "two", "three", "four"};
  print_set("set1", set1);

  set1.insert("ten");
  set1.insert("four"); // will be single "four" present
  print_set("inserted ten & four", set1);

  // find erase element three
  set<string>::iterator it = set1.find("three");
  if(it != set1.end()) {
    cout << "found in set. erasing...\n";
    set1.erase(it);
  }

  print_set("After erase", set1);

  return 0;
}