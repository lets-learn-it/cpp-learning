#include<bits/stdc++.h>
using namespace std;

#define printa(x,n) for(int i=0;i<n;i++) cerr<<x[i]<<" "; cerr<<endl;
#define DEBUG(x) cerr<<">>> "<<#x<<" : "<<x<<endl;

typedef enum {
  NOT_VISITED,
  UNDER_VISIT,
  VISITED
}NODE_STATUS;

void topological_ordering(vector<vector<pair<int, int>>> graph) {
  int nodes = graph.size();
  int topo[nodes] = {0};             // final topological ordering
  int pos = nodes - 1;               // position in topo from end of array
  NODE_STATUS is_visited[nodes] = {NOT_VISITED};  // dont visit same node twice

  // 2 stacks are required to perform DFS while keeping track of visited nodes
  stack<int> s1, s2;

  // iterate over all nodes and start DFS
  for (int i=0; i<nodes; i++) {
    if (is_visited[i] == VISITED) {
      continue;
    }

    // put current node in stack
    s1.push(i);
    while (!s1.empty()) {
      int current = s1.top();
      s1.pop();
      s2.push(current);
      is_visited[current] = UNDER_VISIT;

      // push all unvisted nodes in s1 stack
      for (auto [b, w] : graph[current]) {
        if (is_visited[b] == NOT_VISITED) {
          s1.push(b);
        } else if (is_visited[b] == UNDER_VISIT) {
          printf("cycle detected...");
          exit(1);
        }
      }
    }

    // add in topo from end
    while (!s2.empty()) {
      int current = s2.top();
      s2.pop();
      is_visited[current] = VISITED;

      topo[pos--] = current;
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