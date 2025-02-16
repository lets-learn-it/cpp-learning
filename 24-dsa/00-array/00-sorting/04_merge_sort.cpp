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
void merge(vector<T>& arr, int l, int mid, int r) {
  int n = r - l + 1;
  vector<T> tmp(n);

  int i=l, j=mid+1, k=0;
  while(i<=mid && j<=r) {
    if (arr[i] <= arr[j]) {
      tmp[k] = arr[i];
      i++;
    } else {
      tmp[k] = arr[j];
      j++;
    }
    k++;
  }

  while(i<=mid) {
    tmp[k] = arr[i];
    k++; i++;
  }

  while(j<=r) {
    tmp[k] = arr[j];
    k++; j++;
  }

  for (int i=0; i<n; i++) {
    arr[l+i] = tmp[i];
  }
}

template <typename T>
void merge_sort(vector<T> &arr, int l, int r) {
  if (l<r) {
    int mid = l + (r-l)/2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid+1, r);

    merge(arr, l, mid, r);
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

    merge_sort(arr, 0, n-1);

    printa(arr, arr.size(), cout);
  }

  clock_t end = clock();
  cerr << "Time: " << ((double)(clock() - end) / CLOCKS_PER_SEC) << endl;
  return 0;
}