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

int findMissing(int arr[], int n) {
  if (n == 2) return (arr[0] + arr[1]) / 2;
  int a01 = abs(arr[0] - arr[1]);
  int a12 = abs(arr[1] - arr[2]);

  int small = a01 < a12 ? a01 : a12;
  int diff = arr[0] < arr[1] ? small : -small;
  int curr = arr[0];
  for (int i=1;i<n;i++) {
    curr += diff;
    if (arr[i] != curr)
      return curr;
  }
  return -1;
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int t;
  cin >> t;

  while(t--) {
    int n;
    cin >> n;
    int arr[n];
    for (int i=0;i<n;i++)
      cin >> arr[i];
    
    cout << findMissing(arr, n) << endl;
  }
  return 0;
}