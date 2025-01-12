# Bit Manipulation

## Operations

```cpp
unsigned int n = 0b00111010;
int mask, i, j;

// get ith bit
mask = (1<<i);
n&mask

// set ith bit
mask = (1<<i);
n|mask

// clear ith bit
mask = ~(1<<i);
n&mask

// flip ith bit
mask = (1<<i);
n^mask

// clear last i bits
mask = ((~0)<<i);
n&mask

// clear i to j bits
mask = ((~0)<<(i+1))|((1<<j)-1);
n&mask
```
