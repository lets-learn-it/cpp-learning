#include<bits/stdc++.h>
#include"union_find.h"
using namespace std;

#define max_heap  priority_queue <int>
#define min_heap  priority_queue <int, vector<int>, greater<int>>
#define bits(n)   bitset<n>

#define printa(x,n) for(int i=0;i<n;i++) cerr<<x[i]<<" "; cerr<<endl;
#define DEBUG(x) cerr<<">>> "<<#x<<" : "<<x<<endl;

int kruskal_algo(vector<tuple<int, int, int>> graph, int nodes) {
  int weight = 0;

  // create union find
  union_find uf(nodes);

  // sort edges as per weight (weight is first in tuple)
  sort(graph.begin(), graph.end());

  // iterate over edges and try to add to tree
  for (const auto [w, a, b] : graph) {
    printf("checking for %d -> %d with weight %d", a, b, w);

    // add to tree
    if (!uf.same(a, b)) {
      printf(" - Added\n");
      weight += w;
      uf.unite(a, b);
    } else {
      printf(" - not added\n");
    }
  }
  return weight;
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("input.txt", "r", stdin);

  // edgelist will be good
  int nodes, edges;
  cin >> nodes;
  cin >> edges;

  vector<tuple<int, int, int>> graph(edges);

  int a, b, w;
  for (int i=0; i<edges; i++) {
    cin >> a >> b >> w;
    graph[i] = {w, a, b};
  }

  cout << kruskal_algo(graph, nodes) << endl;
  return 0;
}