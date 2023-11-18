# graph

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

## Traversal

### Breadth first traversal (BFS)

**pseudocode**

- create `visited` boolean array of size nodes V
- create `queue`
- push first node in queue and mark it visited
- Loop till queue is not empty
	- get first element and remove it
	- print first element
	- find all adjacent nodes and push them in queue and mark them visited

**uses**

- Shortest path in graph
- web crawlers
- Social Network
- Cycle detection
- To test if graph is bipartite
- Broadcating in network
- Ford Fulkerson algo

### Depth first traversal (DFS)

**pseudocode**

- create `visited` boolean array of size nodes V
- create `stack`
- push first node in stack and mark it visited
- Loop till stack is not empty
	- get first element and remove it
	- print first element
	- find all adjacent nodes and push them in stack and mark them visited

**uses**

- Detecting Cycle
- Topological sorting
- Finding strongly connected components
- Path finding
- to test if graph is bi partite
- solving puzzle with only 1 solution. eg maze