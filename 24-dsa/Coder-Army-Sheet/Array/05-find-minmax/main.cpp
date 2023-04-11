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

pair<long long, long long> getMinMax(long long a[], int n) {
  pair<long long, long long> minmax (a[0], a[0]);
  for (int i=1;i<n;i++) {
    if (a[i] < minmax.first) 
      minmax.first = a[i];
    else if (a[i] > minmax.second)
      minmax.second = a[i];
  }
  return minmax;
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int t;
  cin >> t;

  while(t--) {
    int n;
    cin >> n;
    long long arr[n];
    for(int i=0;i<n;i++)
      cin >> arr[i];
    
    pair<long long, long long> p = getMinMax(arr, n);
    cout << p.first << " " << p.second << endl;
  }
  return 0;
}