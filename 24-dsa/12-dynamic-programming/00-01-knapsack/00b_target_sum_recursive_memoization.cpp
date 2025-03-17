#include<bits/stdc++.h>
using namespace std;

int expr(vector<int>& nums, int target, int cal, int n, map<pair<int, int>, int>& dp, int& callcount) {
  callcount++;
  if (n==0 && cal == target) {
      return 1;
  } else if (n==0) return 0;

  if (dp.find({n-1, cal}) != dp.end()) return dp[{n-1, cal}];
  dp[{n-1, cal}] = expr(nums, target, cal+nums[n-1], n-1, dp, callcount) + expr(nums, target, cal-nums[n-1], n-1, dp, callcount);
  return dp[{n-1, cal}];
}

int findTargetSumWays(vector<int>& nums, int target) {
  map<pair<int, int>, int> dp;
  int callcount = 0;
  int ans = expr(nums, target, 0, nums.size(), dp, callcount);
  cout << "callcount: " << callcount << endl;
  return callcount;
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
