#include<bits/stdc++.h>
using namespace std;
// https://www.spoj.com/problems/BOOKGFT/

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

  int t;
  cin>>t;

  while(t--) {
    int children, books;
    cin >> children >> books;

    if (books % children == 0) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}

/*
4
2 6
10 12
150 1500
1 1
*/