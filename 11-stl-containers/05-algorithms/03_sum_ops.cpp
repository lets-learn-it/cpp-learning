#include<numeric>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define printa(x,n) for(int i=0;i<n;i++) cerr<<x[i]<<" "; cerr<<endl;

int main(int argc, char const *argv[]) {
  vector<int> v = {1,2,3,4,5,6,7,8,9,10};

  // accumulate
  // initial value is 0
  cout << accumulate(v.begin(), v.end(), 0) << endl;

  // change to double
  cout << accumulate(v.begin(), v.end(), double(0)) << endl;

  // partial_sum (running sum)
  vector<int> prefixsum(v.size());
  partial_sum(v.begin(), v.end(), prefixsum.begin());
  printa(prefixsum, prefixsum.size());

  return 0;
}