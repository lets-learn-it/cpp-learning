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

vector<int> pascal_row(int n) {
  vector<int> ans(n, 1);

  // go from 1st to 2nd last as
  // we know 1st and last value is 1
  for (int i=1; i<n; i++) {
    ans[i] = ans[i-1] * (n - i);
    ans[i] /= i;
  }
  return ans;
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("02.txt", "r", stdin);

  int t = 0;
  cin >> t;

  while(t--) {
    int n = 0;
    cin >> n;

    auto row = pascal_row(n);
    printa(row, row.size());
  }

  return 0;
}