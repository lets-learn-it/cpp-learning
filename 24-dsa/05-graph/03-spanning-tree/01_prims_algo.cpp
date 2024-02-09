#include<bits/stdc++.h>
using namespace std;

#define max_heap  priority_queue <int>
#define min_heap  priority_queue <int, vector<int>, greater<int>>
#define bits(n)   bitset<n>

#define printa(x,n) for(int i=0;i<n;i++) cerr<<x[i]<<" "; cerr<<endl;
#define DEBUG(x) cerr<<">>> "<<#x<<" : "<<x<<endl;

struct ComparePairs {
  bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) {
    return p1.first > p2.first;
  }
};

int prim_algo(vector<vector<pair<int, int>>> graph, int nodes) {
  // first one is weight & second is destination
  // we don't care about source as source is already in tree
  priority_queue<pair<int, int>, vector<pair<int, int>>, ComparePairs> q;
  bool is_included[nodes] = {false};

  // include first node in tree
  is_included[0] = true;
  // add all edges to priority_queue
  for (auto [b, w] : graph[0]) {
    q.push({w, b});
  }

  // loop for node - 1
  // get edge out from priority queue and check
  int i=0;
  int weight = 0;
  while (i < nodes-1) {
    auto [w, b] = q.top();
    q.pop();

    // push all edges from b
    for (auto &[b1, w1] : graph[b]) {
      // check if b1 is part of tree, if not add to heap
      if (!is_included[b1])
        q.push({w1, b1});
    }

    // check if b is already part of tree
    if (is_included[b]) {
      printf("Excluding edge to %d with weight %d\n", b, w);
      continue;
    }

    // add b in tree with current edge
    printf("Including edge to %d with weight %d\n", b, w);
    is_included[b] = true;
    weight += w;
    i++;
  }

  return weight;
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("input.txt", "r", stdin);

  // adjacency list will be good
  int nodes, edges;
  cin >> nodes;
  cin >> edges;

  vector<vector<pair<int, int>>> graph(nodes);

  int a, b, w;
  for (int i=0; i<edges; i++) {
    cin >> a >> b >> w;
    graph[a].push_back({b, w});
    graph[b].push_back({a, w});
  }

  cout << prim_algo(graph, nodes) << endl;
  return 0;
}