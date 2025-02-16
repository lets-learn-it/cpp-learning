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

template<typename T>
int partition(vector<T>& arr, int l, int r) {
  int pivot = arr[r];
  int i=l-1;

  for (int j=l; j<r; j++) {
    if (arr[j] < pivot) {
      i++;
      swap(arr[i], arr[j]);
    }
  }

  swap(arr[i+1], arr[r]);
  return i+1;
}

template <typename T>
void quick_sort(vector<T> &arr, int l, int r) {
  if (l<r) {
    int pivot = partition(arr, l, r);

    quick_sort(arr, l, pivot-1);
    quick_sort(arr, pivot+1, r);
  }
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("integers.txt", "r", stdin);
  freopen("output.gen.txt", "w", stdout);
  clock_t start = clock();

  int t=0;
  cin >> t;

  while(t--) {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i=0; i<n; i++) {
      cin >> arr[i];
    }

    quick_sort(arr, 0, n-1);

    printa(arr, arr.size(), cout);
  }

  clock_t end = clock();
  cerr << "Time: " << ((double)(clock() - end) / CLOCKS_PER_SEC) << endl;
  return 0;
}