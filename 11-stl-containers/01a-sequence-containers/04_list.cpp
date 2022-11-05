#include <iostream>
#include <list>
using namespace std;
/* 
 * Lists do not support random access
 */

// print elements of list
template<typename T>
void printl(const char *s, list<T> &l) {
  cout << s << ": ";
  for(T &i : l) cout << i << " ";
  cout << endl;
}

void message(const char *s) { cout << s << endl; }
void message(const char *s, const int n) { cout << s << ": " << n << endl; } 

int main() {
  list<int> l1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  printl("List", l1);

  // info
  message("size", (int) l1.size());
  message("front", l1.front());
  message("back of l1", l1.back());
  
  l1.push_back(47);
  printl("push_back 47", l1);

  l1.push_front(78);
  printl("push_front 47", l1);

  // iterator to insert & erase
  list<int>::iterator it1 = l1.begin();
  while((*++it1 != 5) && (it1 != l1.end())); // iterate till it1 either points to 5 or end
  if (it1 != l1.end()) {
    l1.insert(it1, 112);
    printl("Inserted 112", l1);
  }

  // erase element using iterator
  it1 = l1.begin();
  while(it1 != l1.end()) {
    if (*it1 == 7) {
      l1.erase(it1);
      printl("Erased 7", l1);
      break;
    }
    it1++;
  }

  // remove element using value
  l1.remove(8);
  printl("removed 8", l1);

  // erase range using iterator
  // remove all elemts from 112 to 9 [112, 9)
  list<int>::iterator it2 = it1 = l1.begin();
  while( (*++it1 != 112) && (it1 != l1.end()) );
  while( (*++it2 != 9) && (it2 != l1.end()) );
  if(it1 != l1.end() && it2 != l1.end()) {
    l1.erase(it1, it2);
    printl("After erasing 112 to 9: ", l1);
  }

  return 0;
}
