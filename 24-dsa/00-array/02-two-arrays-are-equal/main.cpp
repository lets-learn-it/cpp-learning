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

bool check(vector<long long> A, vector<long long> B, int N) {
  unordered_map<long long, int> map;
  for (int i=0;i<N;i++) 
    map[A[i]]++;
  
  for (int i=0;i<N;i++) {
    if (map.find(B[i]) == map.end()) return false;
    map[B[i]]--;
    if (map[B[i]] < 0) return false;
  }
  return true;
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  // freopen("input.txt", "r", stdin);
  int t;
  cin >> t;

  while(t--) {
    int n;
    cin >> n;
    vector<long long> arr(n), brr(n);
    for (int i=0;i<n;i++)
      cin >> arr[i];
    for (int i=0;i<n;i++)
      cin >> brr[i];
    cout << check(arr, brr, n) << endl;
  }
  return 0;
}