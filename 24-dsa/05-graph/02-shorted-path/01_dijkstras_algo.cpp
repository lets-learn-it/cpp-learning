#include<bits/stdc++.h>
using namespace std;

#define printa(x,n) for(int i=0;i<n;i++) cerr<<x[i]<<" "; cerr<<endl;
#define DEBUG(x) cerr<<">>> "<<#x<<" : "<<x<<endl;

void shortest_path(vector<vector<pair<int, int>>> graph, int nodes, int start) {
  priority_queue<pair<int, int>> q;
  int distance[nodes];
  bool processed[nodes];

  for (int i=0; i<nodes; i++) {
    distance[i] = INT_MAX;
    processed[i] = false;
  }

  distance[start] = 0;
  q.push({0, start});

  while (!q.empty()) {
    int a = q.top().second; q.pop();
    if (processed[a]) continue;
    processed[a] = true;

    for (auto u: graph[a]) {
      int b = u.first, w = u.second;
      if (distance[a] + w < distance[b]) {
        distance[b] = distance[a] + w;
        q.push({-distance[b], b});   // default cpp priority_queue finds maximum element.
      }
    }
  }

  for (int i=0; i<nodes; i++) {
    cout << i << " :" << distance[i] << endl;
  }
}

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

  shortest_path(graph, nodes, 0);
  return 0;
}