#include<bits/stdc++.h>
using namespace std;

#define endl      "\n"
#define ld        long double
#define lli       long long int
#define max_heap  priority_queue <int>
#define min_heap  priority_queue <int, vector<int>, greater<int>>
#define bits(n)   bitset<n>

#define printa(x,n) for(int i=0;i<n;i++) cerr<<x[i]<<" "; cerr<<endl;
#define printm(x, m, n) for(int i=0;i<m;i++) {for(int j=0;j<n;j++) cerr<<x[i][j]<<" "; cerr<<endl;}cerr<<endl;
#define DEBUG(x) cerr<<">>> "<<#x<<" : "<<x<<endl;

void setZeroes(vector<vector<int>>& matrix) {
  set<int> rows, cols;
  int r = matrix.size(), c = matrix[0].size();
  for (int i=0; i<r; i++) {
    for (int j=0; j<c; j++) {
      if (matrix[i][j] == 0) {
        rows.insert(i);
        cols.insert(j);
      }
    }
  }

  for (auto i: rows) {
    for (int j=0; j<c; j++) {
      matrix[i][j] = 0;
    }
  }

  for (auto i: cols) {
    for (int j=0; j<r; j++) {
      matrix[j][i] = 0;
    }
  }
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("input.txt", "r", stdin);

  int t;
  cin >> t;

  while (t--) {
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));
    for (int i=0; i<rows; i++) {
      for (int j=0; j<cols; j++) {
        cin >> matrix[i][j];
      }
    }

    setZeroes(matrix);
    printm(matrix, rows, cols);
  }
  return 0;
}
