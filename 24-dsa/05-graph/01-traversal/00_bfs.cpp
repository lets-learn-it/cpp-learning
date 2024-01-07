#include<bits/stdc++.h>
using namespace std;

#define printa(x,n) for(int i=0;i<n;i++) cerr<<x[i]<<" "; cerr<<endl;
#define DEBUG(x) cerr<<">>> "<<#x<<" : "<<x<<endl;

void bfs(vector<vector<pair<int, int>>> graph) {
  int start = 0;
  queue<int> q;
  bool visited[graph.size()];
  for (int i=0; i<graph.size(); i++) {
    visited[i] = false;
  }
  visited[0] = true;
  q.push(start);

  while (!q.empty()) {
    int current = q.front();
    cout << current << " ";
    q.pop();

    for (int i=0; i<graph[current].size(); i++) {
      if (!visited[graph[current][i].first]) {
        visited[graph[current][i].first] = true;
        q.push(graph[current][i].first);
      }
    }
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

  bfs(graph);
  return 0;
}