#include<bits/stdc++.h>
using namespace std;

#define endl      "\n"
#define ld        long double
#define lli       long long int
#define max_heap  priority_queue <int>
#define min_heap  priority_queue <int, vector<int>, greater<int>>
#define bits(n)   bitset<n>

#define printa(x,n,out) for(int i=0;i<n;i++) out<<x[i]<<" "; out<<endl;
#define DEBUG(x) cerr<<">>> "<<#x<<" : "<<x<<endl;

template <typename T>
void selection_sort(vector<T> &arr) {
  size_t min_index;

  for (size_t i = 0; i < arr.size(); i++) {
    min_index = i;
    for (size_t j = i+1; j < arr.size(); j++) {
      if (arr[j] < arr[min_index]) {
        min_index = j;
      }
    }

    if (min_index != i) {
      std::swap(arr[i], arr[min_index]);
    }
  }
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("integers.txt", "r", stdin);
  freopen("output.gen.txt", "w", stdout);
  clock_t start = clock();

  int n;
  cin >> n;
  vector<int> arr(n);

  for (int i=0; i<n; i++) {
    cin >> arr[i];
  }

  selection_sort(arr);

  printa(arr, arr.size(), cout);

  clock_t end = clock();
  cerr << "Time: " << ((double)(clock() - end) / CLOCKS_PER_SEC) << endl;
  return 0;
}