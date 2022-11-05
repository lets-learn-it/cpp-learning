#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <string>
using namespace std;

/* 
 * 
 */

template<typename T>
void reportstk(const char *s, T &stk) {
  cout << s << ": [ size: " << stk.size() << ", top: " << stk.top() << " ]\n";
}

int main() {
  // stack from vector
  vector<int> v1 = {1,2,3,4,5};
  stack<int, vector<int>> s1(v1);
  reportstk("stack s1", s1);
  
  // push to stack
  s1.push(6);
  reportstk("pushed", s1);

  // check top & pop from stack
  cout << "Top of s1: " << s1.top() << endl;
  s1.pop();
  reportstk("after pop", s1);

  // pop all
  while (!s1.empty()) {
    cout << "popping from stack..." << s1.top() << endl;
    s1.pop();
  }
  
  return 0;
}