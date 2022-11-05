#include <iostream>
#include <list>
#include <deque>
#include <queue>
#include <string>
using namespace std;

template <typename T>
void report_queue(const char *s, T &q) {
  cout << s << ": [ size: " << q.size() << ", front: " << q.front() << ", back: " << q.back() << " ]\n"; 
}

int main() {
  // queue from list
  list<int> l1 = {1,2,3,4,5};
  queue<int, list<int>> q1(l1);
  report_queue("q1", q1);

  // queue from deque
  deque<int> d1 = {1,2,3,4,5};
  queue<int, deque<int>> q2(d1);
  report_queue("q2", q2);

  // read and pop element
  cout << q1.front() << " will be popped..." << endl;
  q1.pop();
  report_queue("q1", q1);

  // pop all elements
  while(!q1.empty()) {
    cout << "popping from q1... " << q1.front() << endl;
    q1.pop();
  }

  cout << "Size of q2: " << q2.size() << endl;

  return 0;
}