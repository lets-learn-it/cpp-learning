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

long long nCr(int n, int r) {
  long long ans = 1;

  // When n == r, nCr will be 1
  if (n == r) return 1;

  // When r = 1, nC1 will be n
  if (r == 1) return n;

  int loop = min(r, n-r);
  for (int i=1;i<=loop;i++) {
    ans *= (n-i+1);
    ans /= i;
  }

  return ans;
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("01.txt", "r", stdin);

  int t = 0;
  cin >> t;

  while(t--) {
    int row = 0, col = 0;
    cin >> row >> col;

    DEBUG(nCr(row-1, col-1));
  }

  return 0;
}
