#include<bits/stdc++.h>
using namespace std;

#define printa(x,n) for(int i=0;i<n;i++) cerr<<x[i]<<" "; cerr<<endl;
#define DEBUG(x) cerr<<">>> "<<#x<<" : "<<x<<endl;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("input.txt", "r", stdin);
  int nodes, edges;

  cin >> nodes;

  cin >> edges;

  vector<tuple<int, int, int>> graph(edges);

  int a, b, w;
  for (int i=0; i<edges; i++) {
    cin >> a >> b >> w;
    graph.push_back({a, b, w});
  }

  for (int i=0; i<edges; i++) {
    const auto [a, b, w] = graph[i];
    cout << a << " -> " << b << endl;
  }
  return 0;
}