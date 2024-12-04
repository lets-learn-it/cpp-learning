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

void bubble_sort(vector<int>& arr) {
  int n = arr.size();
  for (int i=0;i<n-1;i++) {
    for (int j=1;j<n-i;j++) {
      if (arr[j-1] > arr[j]) swap(arr[j-1], arr[j]);
    }
  }
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("input.txt", "r", stdin);

  int t=0;
  cin >> t;

  while(t--) {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i=0; i<n; i++) {
      cin >> arr[i];
    }

    bubble_sort(arr);

    printa(arr, arr.size());
  }

  return 0;
}
