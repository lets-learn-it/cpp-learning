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

void insertion_sort(vector<int>& arr) {
  int n = arr.size();

  for (int i=1;i<n;i++) {
    int tmp = arr[i];
    int j=i-1;
    for (; j>=0 && arr[j] > tmp; j--) {
      arr[j+1] = arr[j];
    }
    arr[j+1] = tmp;
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

    insertion_sort(arr);

    printa(arr, arr.size());
  }

  return 0;
}
