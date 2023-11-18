# heap (binary)

> A Heap is a special Tree-based data structure in which the tree is a complete binary tree.

## Types of heaps

1. **Max-Heap**: In a Max-Heap the key present at the root node must be greatest among the keys present at all of it’s children. The same property must be recursively true for all sub-trees in that Binary Tree.
2. **Min-Heap**: In a Min-Heap the key present at the root node must be minimum among the keys present at all of it’s children. The same property must be recursively true for all sub-trees in that Binary Tree.

## Operations

### Inserting new node (max heap)

- Add new element in the next empty spot in the heap, in the right most position in the last level of the heap
- If parent is bigger (depends on type of heap), swap with parent
- This element keeps getting bubbled up in the tree until it either reaches the root of the heap or it has been placed in the right order.

### Removing root node (max heap)

- Remove root and put right most node in the last level of the heap at root position.
- If larger child is large than this node, swap it with child.
- This element keeps getting bubbled down in the tree until it either reaches the last level of the heap or it has been placed in the right position