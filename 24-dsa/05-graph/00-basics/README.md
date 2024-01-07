# Graph Basics

- **degree of node** is number of its neighbors.
- The sum of degrees in a graph is always `2m`, where `m` is number of edges.
- Graph is **complete** if degree of every node is `n-1`.
- A graph is **bipartite** if it is possible to color its nodes using two colors in such a way that no adjacent nodes have the same color.
  A graph is bipartite exactly when it **does not have a cycle with odd number of edges.**

## Representation

### Matrix Representation

**Pros**
- Easy to implement
- Removing edge takes $O(1)$ time
- queries are efficient

**Cons**
- consumes more space $O(v^2)$
- Adding vertex takes $O(v^2)$ time

**Example**

```cpp
int graph[4][4] = {0};

// add edge 0->2
graph[0][2] = 1;  // can add weight
```

### Adjacency list representation

**Pros**
- saves space $O(|v| + |E|)$.  worst case $O(v^2)$
- Adding vertex is easy

**Cons**
- Queries like whether there is edge from vertex $u$ to $v$ takes $O(v)$

**Example**

```cpp
// nodes: number of nodes
vector<<vector<pair<int,int>>> graph(nodes);

// add node
graph.push_back({});

// add edge 2->3 with weight 4
graph[2].push_back(make_pair(3,4));
```