#include<bits/stdc++.h>
using namespace std;

#define endl      "\n"
#define ld        long double
#define lli       long long int
#define max_heap  priority_queue <int>
#define min_heap  priority_queue <int, vector<int>, greater<int>>
#define bits(n)   bitset<n>

#define printa(x,n) for(int i=0;i<n;i++) cerr<<x[i]<<" "; cerr<<endl;
#define DEBUG(x) cerr<<">>> "<<#x<<" : "<<x<<endl;

int lower_bound(vector<int>& arr, int val) {
  int n = arr.size();
  if (arr[0] > val) return -1;

  int l = 0, r = n - 1;

  while(l <= r) {
    int mid = l + ((r - l) / 2);
    if (arr[mid] == val) return val;
    if (arr[mid] > val) r = mid - 1;
    else l = mid + 1;
  }
  return arr[r];
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("input.txt", "r", stdin);

  int t;
  cin >> t;

  while(t--) {
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);

    for (int i=0;i<n;i++) {
      cin >> arr[i];
    }

    cout << lower_bound(arr, x) << endl;
  }
  return 0;
}
