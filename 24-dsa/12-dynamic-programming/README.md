# Dynamic Programming

> It is an algorithmic paradigm that solves a given complex problem by breaking it into subproblems and stores the results of subproblems to avoid computing the same results again.

## Problem Types

### 0-1 knapsack

- [0-1 knapsack - gfg](https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1)
- [494 Target sum - leetcode](https://leetcode.com/problems/target-sum/description/)
- [416 Partition equal subset sum - leetcode](https://leetcode.com/problems/partition-equal-subset-sum/description/)
- [subset sum - gfg](https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1)
- [diff of subset sum minimum - gfg](https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1)
- [subsequences/partitions with given difference - gfg](https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1)

### Unbounded knapsack

- [knapsack with duplicate items - gfg](https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1)
- [322 coin change (fewest number of coins) - leetcode](https://leetcode.com/problems/coin-change/description/)
- [518 coin change 2 (number of combinations that make up that amount) - leetcode](https://leetcode.com/problems/coin-change-ii/description/)
- [rod cutting - gfg](https://www.geeksforgeeks.org/problems/rod-cutting0840/1)

### Fibonacci

### Longest common subsequence (LCS)

- [LCS - gfg](https://www.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1)
- [LCS - leetcode](https://leetcode.com/problems/longest-common-subsequence/description/)
- [583 delete ops for two strings to make same - leetcode](https://leetcode.com/problems/delete-operation-for-two-strings/)
- [72 edit distance (ops:add,del,replace) - leetcode](https://leetcode.com/problems/edit-distance/)
- [1092 shortest common supersequence - leetcode](https://leetcode.com/problems/shortest-common-supersequence/description/)
- [516 longest palindromic subsequence - leetcode](https://leetcode.com/problems/longest-palindromic-subsequence/description/)

### Longest increasing subsequence (LIS)

- [length LIS -gfg](https://www.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1)
- [number of LIS - gfg](https://www.geeksforgeeks.org/problems/number-of-longest-increasing-subsequence/1)
- [box stacking - gfg](https://www.geeksforgeeks.org/problems/box-stacking/1)

### Kadane's Algorithm

### Matrix chain multiplication

### DP on trees

### DP on grids

### Other

## Properties of dynamic programming

### 1. Overlapping Subproblems

- It is mainly used when solutions of same subproblems are needed again and again.
- computed solutions to subproblems are stored in a table so that these don’t have to be recomputed.

**Example of fibonacci series**

```cpp
int fib(int n) {
  if ( n <= 1 )
    return n;
  return fib(n-1) + fib(n-2);
}
```

**Recursive Tree**

```
                         fib(5)
                     /             \
               fib(4)                fib(3)
             /      \                /     \
         fib(3)      fib(2)         fib(2)    fib(1)
        /     \        /    \       /    \
  fib(2)   fib(1)  fib(1) fib(0) fib(1) fib(0)
  /    \
fib(1) fib(0)
```

**There are 2 methods we can store these values**

1. **Memoization (Top Down)**:  The memoized program for a problem is similar to the recursive version with a small modification that it looks into a lookup table before computing solutions.

```cpp
int lookup[1000] = {0};

int fib(int n) {
  if (lookup[n] == 0) {
    if (n <= 1)
      lookup[n] = n;
    else
      lookup[n] = fib(n - 1) + fib(n - 2);
  }
  return lookup[n];
}
```

3. **Tabulation (Bottom Up)**: The tabulated program for a given problem builds a table in bottom up fashion and returns the last entry from table. For example, for the same Fibonacci number, we first calculate fib(0) then fib(1) then fib(2) then fib(3) and so on. So literally, we are building the solutions of subproblems bottom-up.

```cpp
int fib(int n) {
  int f[n+1];
  int i;
  f[0] = 0;   f[1] = 1;
  for (i = 2; i <= n; i++)
    f[i] = f[i-1] + f[i-2];

  return f[n];
}
```

### 2. Optimal Substructure

- A given problems has Optimal Substructure Property **if optimal solution of the given problem can be obtained by using optimal solutions of its subproblems.**
- If a node x lies in the shortest path from a source node u to destination node v then the shortest path from u to v is combination of shortest path from u to x and shortest path from x to v. The standard All Pair Shortest Path algorithms like Floyd–Warshall and Bellman–Ford are typical examples of Dynamic Programming.

## How to solve dynamic programming problem?

1. **Identify if it is a DP problem**:
  - Typically, all the problems that require maximizing or minimize certain quantities or counting problems that say to count the arrangements under certain conditions or certain probability problems can be solved by using Dynamic Programming.
  -  All dynamic programming problems satisfy the overlapping subproblems property and most of the classic dynamic problems also satisfy the optimal substructure property. Once, we observe these properties in a given problem, be sure that it can be solved using DP.
2. **decide a state expression with least parameters**
  - **State** can be defined as the set of parameters that can uniquely identify a certain position or standing in the given problem. This set of parameters should be as small as possible to reduce state space.
  - For example: In our famous Knapsack problem, we define our state by two parameters index and weight i.e DP[index][weight]. Here DP[index][weight] tells us the maximum profit it can make by taking items from range 0 to index having the capacity of sack to be weight. Therefore, here the parameters index and weight together can uniquely identify a subproblem for the knapsack problem.
3. **Formulate state relationship**
4. **Do tabulation (or add memoization)**

## Bit mask

- First thing to make sure before using bitmasks for solving a problem is that it must be having small constraints, as solutions which use bitmasking generally take up exponential time and memory.
- Mask in Bitmask means hiding something. Bitmask is nothing but a binary number that represents something.
- Consider the set $A = \{1, 2, 3, 4, 5\}$ . We can represent any subset of A using a bitmask of length 5, with an assumption that if $i^{th} (0 \leq i \leq 4)$ bit is set then it means $i^{th}$ element is present in subset. So the bitmask 01010 represents the subset  $\{2,4\}$

```cpp
// set ith bit
b | (1 << i)

// unset ith bit
b & !(1 << i)

// check ith bit is set or not
b & (1 << i) != 0
```

## References

[Dynamic Programming Playlist by Aditya Verma](https://www.youtube.com/playlist?list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go)
