#include<bits/stdc++.h>
using namespace std;

#define printa(x,n) for(int i=0;i<n;i++) cerr<<x[i]<<" "; cerr<<endl;
#define DEBUG(x) cerr<<">>> "<<#x<<" : "<<x<<endl;

const bool directed = false;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("input.txt", "r", stdin);
  int nodes, edges;

  cin >> nodes;

  int graph[nodes][nodes];
  for (int i=0; i<nodes; i++) {
    for (int j=0; j<nodes; j++) {
      graph[i][j] = 0;
    }
  }

  cin >> edges;

  int a, b, w;
  for (int i=0; i<edges; i++) {
    cin >> a >> b >> w;
    graph[a][b] = w;
    if (!directed) {
      graph[b][a] = w;
    }
  }

  for (int i=0; i<nodes; i++) {
    for (int j=0; j<nodes; j++) {
      if (graph[i][j] > 0) {
        cout << i << " -> " << j << endl;
      }
    }
  }
  return 0;
}