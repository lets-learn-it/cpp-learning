# Spanning Tree

- Spanning tree of graph consists of all nodes of the graph and some of the edges of the graph so that there is a path between any two nodes.
- Like trees in general, spanning trees are connected and acyclic
- *weight of spanning tree* is sum of its edge weights.
- **Minimum spanning tree** is a spanning tree whose weight is as small as possible. **Maximum spanning tree** is spanning tree whose weight is as large as possible.
- **Graph may have several minimum and maximum spanning trees**, so the trees are not unique.

## Kruskal's Algorithm

- Initial spanning tree only contains the nodes of the graph and does not contain any edges.
- Go through edges **ordered by their weight** and always adds an edge to tree if it does not create cycle.

### Union Find Structure

- It maintains a **collection of sets**. The sets are **disjoint**, so no element belongs to more than one set.
- Two $O(\log{N})$ time operations are supported.
  - `unite`: joins two sets
  - `find`: finds the representative/leader of set that contains a given element.

```cpp
// At start each element is leader of their own set.

// link contains for each element the next element in the chain or element itself if it is leader.
// size indicates size of corresponding set
for (int i=1; i<=n; i++) link[i] = i;
for (int i=1; i<=n; i++) size[i] = 1;

// find leader of element
int find(int x) {
  while (x != link[x])
    x = link[x];
  return x;
}

// unite 2 sets.
// connect smaller set to larger set
void unite(int a, int b) {
  a = find(a);
  b = find(b);
  if (size[a] < size[b]) swap(a, b);
  size[a] += size[b];
  link[b] = a;
}
```

## Prim's Algorithm

- Algorithm first adds an arbitrary node to the tree. After this, algorithm always chooses a minimum weight edge that adds new node to the tree.
- create set which keeps track of vertices already included.

#### Pseudocode

- select an arbitrary vertex $s$ to start the tree from
  - while (there are still non tree vertices)
    - select the edge of minimum weight between a tree and non tree vertex
    - add selected edge and vertex to tree
    - add all edges from that node to set