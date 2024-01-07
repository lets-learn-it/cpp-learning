# Shortest Path

## Bellman Ford Algorithm

- It finds shortest paths from starting node to all nodes of graph.
- Algorithm can process all kinds of graphs except **graph contain a cycle with negative length**.
- algorithm consisists of `n-1` rounds, and on each round algorithm goes through all edges of the graph and attempts to reduce the distances.
- It constructs array `distance` that will contain the distances from node `x` to all nodes.
- **graph in edge list form will be helpful**, because we will be traversing over edges exactly `n-1` times.
- time complexity is $O(nodes . edges)$

### Negative Cycle

- This algorithm can also be used to check if graph contains a cycle with negative length.
- In this case, **any path that contains the cycle can be shortened infinitely many times**, so the concept of shortest path is not meaningful.
- To detect negative cycle, run algorithm for `n` rounds and check distance with `n-1` rounds. If they are reduced further then negative cycle exists.

## Dijkstra's Algorithm

- It finds shortest paths from starting node to all nodes of graph.
- **Requires no negative weight edges** in graph.
- **Algorithm**
  - Like bellman-ford, this algorithm maintains `distance` array and reduces then during search.
  - For each round, it selects a node that has not been processed yet and whose distance is as small as possible.
  - Then it goes through all edges that start at node and reduces the distances using them.
- It is **more efficient** because it only processes **each edge in graph once** and can be used for processing large graphs.
- **graph in adjacency list form will be helpful**, because we will be traversing over edges which are originating from particular node.
- time complexity is $O(nodes + edges \log{edges})$

### Floyd-Warshall Algorithm

- It finds shortest paths between all node pairs of graph in single run.
- Algorithm maintains matrix that contains distance between nodes. Initial matrix is directly constructed based on adjacency matrix of graph. pairs who do not have direct connection are marked as infinite.
- **In each round, it selects a new node that can act as an intermediate node in paths from now on, and reduces distances using this node.**
- time complexity of algorithm is $O(n^3)$