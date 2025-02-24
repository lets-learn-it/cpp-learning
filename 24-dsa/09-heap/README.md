# Heap

```cpp
// primary operations
T top();
bool push(T);
bool pop();

// secondary operations
delete();       // delete other than root
decreaseKey();  // decrease other than root
```

## Binary heap

- heap is **complete binary tree** that satisfies heap property
- **Heap property**:
  - Max heap: for every node, `node.value >= node.left.value && node.value >= node.right.value`
  - Min heap: for every node, `node.value <= node.left.value && node.value <= node.right.value`
- **Notes**
  - We will implement it using array
  - `arr[0]` will be root
  - `arr[(i-1)/2]` returns parent node
  - `arr[(2*i)+1]` left child & `arr[(2*i)+2)]` right node