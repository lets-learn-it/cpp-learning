# Binary Tree

- Each node in binary tree contains `data`, `left pointer`, `right pointer`

```cpp
struct node {
  int data;
  struct node* left;
  struct node* right;
};

// cpp
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
      this.data = data;
      left = nullptr;
      right = nullptr;
    }
};
```

### Operations on Binary Tree

- Inserting element
- Removing element
- Searching element
- Traversal
  - DFS
    - Preorder (current-left-right)
    - Inorder (left-current-right)
    - Postorder (left-right-current)
  - BFS
- Finding height of tree
- Finding level of tree

### Properties of Binary Tree

- Maximum number of nodes at level `l` of a binary tree is $2^l$.
- Maximum number of nodes in a binary tree of height `h` is $2^h - 1$
- In Binary tree with `N` nodes, the minimum possible height or minimum number of levels is $\log_{2}{(N+1)}$
- Binary tree with `L` leaves has at least $|\log_{2}L| + 1$
- In binary tree where every node has 0 or 2 children, the number of leaf nodes is always one more than nodes with two children.
- In a non-empty binary tree, if `n` is total number of nodes and `e` is total number of edges, then $e = n - 1$
