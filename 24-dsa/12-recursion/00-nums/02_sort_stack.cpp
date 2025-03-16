#include<bits/stdc++.h>
using namespace std;

void sorts(stack<int>& s, int num) {
  if (s.empty()) {
    s.push(num);
    return;
  } else {
    int tmp = s.top(); s.pop();
    if (tmp >= num) {
      s.push(tmp); s.push(num);
      return;
    }
    sorts(s, num);
    s.push(tmp);
  }
}

void pop(stack<int>& s) {
  if (s.empty()) return;

  int tmp = s.top(); s.pop();
  pop(s);
  sorts(s, tmp);
}




int main(int argc, char const *argv[]) {
  vector<int> vec = {1,2,3,5,6,7,4,6,87,54,32};
  stack<int> s;

  for (auto& num : vec) {
    s.push(num);
  }
  pop(s);

  while(!s.empty()) {
    cout << s.top() << " ";
    s.pop();
  }

  cout << endl;

  return 0;
}