#include<bits/stdc++.h>
using namespace std;

#define endl        "\n"
#define ld          long double
#define lli         long long int
#define max_heap    priority_queue <int>
#define min_heap    priority_queue <int, vector<int>, greater<int>>
#define bits(n)     bitset<n>

#define printa(x,n) for(int i=0;i<n;i++) cerr<<x[i]<<" "; cerr<<endl;
#define debug(x) cerr<<">>> "<<#x<<" : "<<x<<endl;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("input.txt", "r", stdin);
  freopen("output.gen.txt", "w", stdout);
  clock_t start = clock();

  bits(INT16_MAX) b{0x0};
  b.set(1, 1);
  debug(b);
  debug(sizeof(b));

  clock_t end = clock();
  cerr << "Time: " << ((double)(clock() - end) / CLOCKS_PER_SEC) << endl;
  return 0;
}