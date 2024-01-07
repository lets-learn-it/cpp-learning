# Graph Traversal

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
- Cycle detection: A graph contains a cycle if during a graph traversal, we find a node whose neighbor (other than the previous node in the current path) has already been visited.
- Bipartiteness Check
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

- Cycle detection
- Topological sorting
- Finding strongly connected components (Connectivity check): A graph is connected if there is a path between any two nodes of the graph. This we can check if a graph is connected by starting at an arbitrary node and finding out if we can reach all other nodes.
- Path finding
- Bipartiteness Check
- solving puzzle with only 1 solution. eg maze