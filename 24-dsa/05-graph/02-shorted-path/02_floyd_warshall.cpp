#include<bits/stdc++.h>
using namespace std;

#define printa(x,n) for(int i=0;i<n;i++) cerr<<x[i]<<" "; cerr<<endl;
#define DEBUG(x) cerr<<">>> "<<#x<<" : "<<x<<endl;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("input.txt", "r", stdin);
  int nodes, edges;

  cin >> nodes;

  int graph[nodes][nodes];
  for (int i=0; i<nodes; i++) {
    for (int j=0; j<nodes; j++) {
      if (i != j)
        graph[i][j] = 1000;  // using INT_MAX overflowing int while calculating distance using intermediate node.
      else
        graph[i][j] = 0;
    }
  }

  cin >> edges;

  int a, b, w;
  for (int i=0; i<edges; i++) {
    cin >> a >> b >> w;
    graph[a][b] = w;
    graph[b][a] = w;
  }

  // floyd-warshall
  for (int k=0; k<nodes; k++) {
    for (int i=0; i<nodes; i++) {
      for (int j=0; j<nodes; j++) {
        graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j]);
      }
    }
  }

  for (int i=0; i<nodes; i++) {
    for (int j=i; j<nodes; j++) {
      cout << i << " -> " << j << " : " << graph[i][j] << endl;
    }
  }
  return 0;
}