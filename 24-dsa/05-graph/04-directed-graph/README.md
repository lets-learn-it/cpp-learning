# Directed Graph

- **Acyclic Graphs**: No cycles in graph.
- **Successor Graphs**: outdegree of each node is 1, so each node has a unique successor.

## Topological Sorting

- It is an ordering of nodes of directed graph such that if there is path from node `a` to node `b`, then node `a` appears before node `b` in the ordering.
- Acyclic graph always has a topological sort.
- Depth-first seach can be used to both check if directed graph contains a cycle and if it does not contain cycle, to construct a topological sort.
