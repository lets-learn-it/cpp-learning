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

int search(int arr[], int N, int X) {
  for (int i=0;i<N;i++) {
    if (arr[i] == X)
      return i;
  }
  return -1;
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("input.txt", "r", stdin);

  int t;
  cin >> t;

  while(t--) {
    int n, x;
    cin >> n >> x;
    int arr[n];

    for (int i=0;i<n;i++) {
      cin >> arr[i];
    }

    cout << search(arr, n, x) << endl;
  }
  return 0;
}