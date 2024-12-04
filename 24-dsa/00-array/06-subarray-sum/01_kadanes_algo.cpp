#include<bits/stdc++.h>
using namespace std;

#define endl      "\n"
#define ld        long double
#define lli       long long int
#define max_heap  priority_queue <int>
#define min_heap  priority_queue <int, vector<int>, greater<int>>
#define bits(n)   bitset<n>

#define printa(x,n) for(int i=0;i<n;i++) cerr<<x[i]<<" "; cerr<<endl;
#define printm(x, m, n) for(int i=0;i<m;i++) {for(int j=0;j<n;j++) cerr<<x[i][j]<<" "; cerr<<endl;} cerr<<endl;
#define DEBUG(x) cerr<<">>> "<<#x<<" : "<<x<<endl;

int max_subarray_sum(vector<int>& arr) {
  int n = arr.size();
  int local_max = 0;
  int global_max = INT_MIN;

  for (int i=0; i<n; i++) {
    local_max = max(arr[i], arr[i] + local_max);
    if (local_max > global_max) global_max = local_max;
  }

  return global_max;
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("input.txt", "r", stdin);

  int t=0;
  cin >> t;

  while(t--) {
    int n=0;
    cin >> n;

    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i];

    int max_sum = max_subarray_sum(arr);
    DEBUG(max_sum);
  }

  return 0;
}