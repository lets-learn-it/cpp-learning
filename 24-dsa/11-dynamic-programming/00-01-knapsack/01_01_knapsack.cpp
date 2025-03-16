#include <iostream>
#include <vector>
using namespace std;

int knapsack_memoization(vector<int>& val, vector<int>& wt, int W, int n, vector<vector<int>>& dp) {
  // base
  if (W==0 || n==0) return 0;

  // check cache
  if (dp[W][n] != -1) return dp[W][n];

  // cache does not have value
  // if current item can be added
  int ifItemAdded = 0;
  if (W >= wt[n-1]) {
    ifItemAdded = val[n-1] + knapsack_memoization(val, wt, W-wt[n-1], n-1, dp);
  }

  // without adding current item
  int ifItemNotAdded = knapsack_memoization(val, wt, W, n-1, dp);

  return dp[W][n] = max(ifItemAdded, ifItemNotAdded);
}

int knapsack_tabulation(vector<int>& val, vector<int>& wt, int W, int n, vector<vector<int>>& dp) {
  // base
  // if knapsack capacity is 0
  for (int i=0; i<n+1; i++) {
    dp[0][i] = 0;
  }

  // if no items available
  for (int i=0; i<W+1; i++) {
    dp[i][0] = 0;
  }

  for (int i=1; i<W+1; i++)  {
    for (int j=1; j<n+1; j++) {
      // if current item can be added
      int ifItemAdded = 0;
      if (i >= wt[j-1]) {
        ifItemAdded = val[j-1] + dp[i-wt[j-1]][j-1];
      }

      // without adding current item
      int ifItemNotAdded = dp[i][j-1];

      dp[i][j] = max(ifItemAdded, ifItemNotAdded);
    }
  }

  return dp[W][n];
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("01_input", "r", stdin);


  int t;
  cin >> t;

  while(t--) {
    int n, W;
    cin >> n >> W;

    vector<int> val(n) , wt(n);

    for (int i=0; i<n; i++) {
      cin >> val[i];
    }

    for (int i=0; i<n; i++) {
      cin >> wt[i];
    }

    // create memory
    vector<vector<int>> dp1(W+1, vector<int>(n+1, -1));
    vector<vector<int>> dp2(W+1, vector<int>(n+1, -1));
    cout << "memoization: " << knapsack_memoization(val, wt, W, n, dp1) << ", tabulation: " << knapsack_tabulation(val, wt, W, n, dp2) << endl;
  }
  return 0;
}
