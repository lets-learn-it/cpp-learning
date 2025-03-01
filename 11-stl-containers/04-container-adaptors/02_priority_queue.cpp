#include <iostream>
#include <queue>
#include <string>
using namespace std;

/*
 * A priority queue is a container adaptor that provides constant time lookup of
 * the largest (by default) element, at the expense of logarithmic insertion and extraction.
 *
 * A user-provided Compare can be supplied to change the ordering,
 * e.g. using std::greater<T> would cause the smallest element to appear as the top()
 *
 * Working with a priority_queue is similar to managing a heap in some random access container,
 * with the benefit of not being able to accidentally invalidate the heap.
 *
 */

template<typename T>
void print_pq(const char *s, T pq) {
  cout << s << ": ";
  while(!pq.empty()) {
    cout << pq.top() << " ";
    pq.pop();
  }
  cout << endl;
}

int main() {
  vector<int> v1 = {4,23,54,11,456,243,6787,3};

  priority_queue<int> q1; // max priority queue / max heap
  for(int n:v1)
    q1.push(n);
  print_pq("q1", q1);

  // min priority queue
  priority_queue<int, vector<int>, greater<int>> minq1(v1.begin(), v1.end());
  print_pq("min q1", minq1);

  // same as above
  priority_queue minq2(v1.begin(), v1.end(), greater<int>());
  print_pq("min q2", minq2);

  // using custom function
  struct {
    bool operator() (const int l, const int r) const { return l > r; }
  } customLess;
  priority_queue minq3(v1.begin(), v1.end(), customLess);
  print_pq("min q3", minq3);

  // using lambda function
  auto cmp = [](int left, int right) { return left > right; };
  // decltype returns type of cmp
  priority_queue<int, vector<int>, decltype(cmp)> minq4(cmp);

  for(int x:v1)
    minq4.push(x);
  print_pq("min q4", minq4);

  return 0;
}
