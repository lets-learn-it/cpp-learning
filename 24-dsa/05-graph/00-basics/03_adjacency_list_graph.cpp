#include<bits/stdc++.h>
using namespace std;

#define printa(x,n) for(int i=0;i<n;i++) cerr<<x[i]<<" "; cerr<<endl;
#define DEBUG(x) cerr<<">>> "<<#x<<" : "<<x<<endl;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("input.txt", "r", stdin);
  int nodes, edges;

  cin >> nodes;

  vector<vector<pair<int, int>>> graph(nodes);

  cin >> edges;

  int a, b, w;
  for (int i=0; i<edges; i++) {
    cin >> a >> b >> w;
    graph[a].push_back({b, w});
  }

  for (int i=0; i<nodes; i++) {
    for (int j=0; j<graph[i].size(); j++) {
      cout << i << " -> " << graph[i][j].first << endl;
    }
  }
  return 0;
}