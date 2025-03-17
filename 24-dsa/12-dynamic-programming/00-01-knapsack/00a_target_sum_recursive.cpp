#include<bits/stdc++.h>
using namespace std;

int expr(vector<int>& nums, int target, int cal, int n, int& callcount) {
  callcount++;
  if (n==0 && cal == target) {
      return 1;
  } else if (n==0) return 0;

  return expr(nums, target, cal+nums[n-1], n-1, callcount) + expr(nums, target, cal-nums[n-1], n-1, callcount);
}

int findTargetSumWays(vector<int>& nums, int target) {
  int callcount = 0;
  int ans = expr(nums, target, 0, nums.size(), callcount);
  cout << "callcount: " << callcount << endl;
  return ans;
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("00_input", "r", stdin);

  int t;
  cin >> t;

  while(t--) {
    int n, target;
    cin >> n >> target;

    vector<int> vec(n);
    for (int i=0; i<n; i++) {
      cin >> vec[i];
    }

    cout << findTargetSumWays(vec, target) << endl;
  }
  return 0;
}
