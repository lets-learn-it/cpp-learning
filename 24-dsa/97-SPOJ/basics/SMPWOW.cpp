#include<bits/stdc++.h>
using namespace std;

// CLEAN DATA TYPES LIKE RUST
#define f32   float
#define f64   double
#define u8    uint8_t
#define u16   uint16_t
#define u32   uint32_t
#define u64   uint64_t
#define i8    int8_t
#define i16   int16_t
#define i32   int32_t
#define i64   int64_t
// AVOID
#define u128  __uint128_t
#define i128  __int128_t
#define f128  long double

#define endl      "\n"
#define max_heap  priority_queue <int>
#define min_heap  priority_queue <int, vector<int>, greater<int>>
#define bits(n)   bitset<n>

#define printa(x,n)   cerr<<"»»» "<<#x<<" { ";for(int i=0;i<n;i++) cerr<<x[i]<<" "; cerr<<"}\n";
#define printm(x,m,n) cerr<<"»»» "<<#x<<" {\n";for(int i=0;i<m;i++){cerr<<"	{ ";for(int j=0;j<n;j++)cerr<<x[i][j]<<" ";cerr<<"}\n";}cerr<<"    }\n"
#define printk(x)     cerr<<"»»» "<<#x<<" { ";for(auto k:x) cerr<<k<<" ";cerr<<"}\n";
#define printkv(x)    cerr<<"»»» "<<#x<<" { ";for(auto [k,v]:x) cerr<<k<<":"<<v<<", ";cerr<<" }\n";
#define DEBUG(x)      cerr<<"»»» "<<#x<<" : "<<x<<endl;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  char ans[n+3];
  ans[0] = 'W';
  ans[n+1] = 'w';
  ans[n+2] = 0;

  for (int i=1; i<=n; i++) {
    ans[i] = 'o';
  }

  cout << ans;
  return 0;
}