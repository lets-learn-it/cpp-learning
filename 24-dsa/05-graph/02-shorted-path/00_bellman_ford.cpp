#include <bits/stdc++.h>
using namespace std;

#define printa(x, n)                               \
  for (int i = 0; i < n; i++) cerr << x[i] << " "; \
  cerr << endl;
#define DEBUG(x) cerr << ">>> " << #x << " : " << x << endl;

void shortest_path(vector<tuple<int, int, int>> graph, int nodes, int start) {
  vector<int> distance(nodes, INT_MAX);
  distance[start] = 0;

  for (int i = 1; i < nodes; i++) {
    for (const auto [a, b, w] : graph) {
      distance[b] = min(distance[b], distance[a] + w);
    }
  }

  for (int i = 0; i < nodes; i++) {
    cout << i << " :" << distance[i] << endl;
  }
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  freopen("input.txt", "r", stdin);
  int nodes, edges;

  cin >> nodes;

  cin >> edges;

  vector<tuple<int, int, int>> graph(edges);

  int a, b, w;
  for (int i = 0; i < edges; i++) {
    cin >> a >> b >> w;
    graph.push_back({a, b, w});
  }

  shortest_path(graph, nodes, 0);
  return 0;
}