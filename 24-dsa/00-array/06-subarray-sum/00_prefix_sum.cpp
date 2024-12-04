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

vector<int> build_prefix_array(vector<int>& arr) {
  int n = arr.size();
  vector<int> prefix(n, 0);

  prefix[0] = arr[0];

  for(int i=1;i<n;i++) {
    prefix[i] = prefix[i-1] + arr[i];
  }

  return prefix;
}

int max_subarray_sum(vector<int>& arr) {
  int n = arr.size();
  int max_sum = arr[0];
  for (int i=0;i<n;i++) {
    for(int j=i;j<n;j++) {
      int subSum = i>0 ? arr[j] - arr[i-1] : arr[j];
      if (max_sum < subSum) max_sum = subSum;
    }
  }
  return max_sum;
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

    auto prefix = build_prefix_array(arr);
    int max_sum = max_subarray_sum(prefix);
    DEBUG(max_sum);
  }

  return 0;
}