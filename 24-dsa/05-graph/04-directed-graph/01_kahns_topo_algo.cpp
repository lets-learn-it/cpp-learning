#include<bits/stdc++.h>
using namespace std;

#define printa(x,n) for(int i=0;i<n;i++) cerr<<x[i]<<" "; cerr<<endl;
#define DEBUG(x) cerr<<">>> "<<#x<<" : "<<x<<endl;

void topological_ordering(vector<vector<pair<int, int>>> graph) {
  int nodes = graph.size();
  vector<int> topo;            // final topological ordering
  int in_degree[nodes] = {0};  // dont visit same node twice

  // find in degree for all nodes
  for (int i=0; i<nodes; i++) {
    for (auto [b, _]: graph[i]) {
      in_degree[b]++;
    }
  }

  queue<int> q;

  // find nodes with 0 indegree and add them in queue
  for (int i=0; i<nodes; i++) {
    if (in_degree[i] == 0) q.push(i);
  }

  // remove nodes from queue till its node empty
  while (!q.empty()) {
    int current = q.front();
    q.pop();

    // reduce indegree of all nodes which are reachable from current node
    // make sure to add in queue if it indegree goes to zero
    for (auto [b, _]: graph[current]) {
      in_degree[b]--;
      if (in_degree[b] == 0) q.push(b);
    }

    topo.push_back(current);
  }

  // check for cycle
  for (int i=0; i<nodes; i++) {
    if (in_degree[i] > 0) {
      printf("Cycle detected...");
      return;
    }
  }

  for (auto &a: topo){
    printf("%d ", a);
  }
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("input.txt", "r", stdin);

  // adjacency list will be good
  int nodes, edges, t;
  cin >> t;

  while(t--) {
    cin >> nodes;
    cin >> edges;

    vector<vector<pair<int, int>>> graph(nodes);

    int a, b, w;
    for (int i=0; i<edges; i++) {
      cin >> a >> b;
      graph[a].push_back({b, 0});
    }

    topological_ordering(graph);
    printf("\n");
  }

  return 0;
}