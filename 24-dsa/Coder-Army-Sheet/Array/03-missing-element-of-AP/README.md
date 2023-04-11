# missing element of AP

## Using sum of AP (will overflow)
- first & last elements are not missing.
- use formula: sum of AP = n * (first + last) / 2
- consider n as total elements given + 1
- answer = sum of AP - sum of all given elements.

## Find difference
- if n == 2, answer = (a[0] + a[1]) / 2
- find difference : a01 = |a[1] - a[0]|, a12 = |a[2] - a[1]|
- find small between a01 & a12, small = a01 < a12 ? a01 : a12;
- find correct sign using diff = a[0] < a[1] ? small : -small

## find difference (Easy one)

- diff = (arr[n-1] - arr[0]) / n
