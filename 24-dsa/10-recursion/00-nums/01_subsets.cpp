#include<bits/stdc++.h>
using namespace std;

void subsets(int i, vector<int>& v, vector<int>& s, vector<vector<int>>& sets) {
  // base case
  if (i == v.size()) {
    sets.push_back(s);
    return;
  }

  // select element
  int x = v[i];

  s.push_back(x);
  subsets(i+1, v, s, sets);

  s.pop_back();
  subsets(i+1, v, s, sets);
}

int main(int argc, char const *argv[]) {
  vector<int> v = {1,2,3};
  vector<vector<int>> sets;
  vector<int> tmp;

  subsets(0, v, tmp, sets);

  for (auto s: sets) {
    for (auto ele:s) {
      cout << ele << " ";
    }
    cout << endl;
  }

  return 0;
}