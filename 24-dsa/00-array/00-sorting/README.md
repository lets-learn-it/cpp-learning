# Sorting

## Selection Sort

> sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning.

### Pseudocode

- Loop $i:0 \rightarrow n$
	- min_ele = i
	- Loop $j:(i+1) \rightarrow n$
		- if arr[j] < arr[max_ele]
			- min_ele = j
	- swap arr[i] & arr[min_ele]

### Code

```cpp
void selection_sort(int *arr, int n) {
  int min_element, temp;

  for(int i=0;i<n;i++) {
    min_element = i;
    for(int j=i+1;j<n;j++) {
      if(arr[j] < arr[min_element]){
        min_element = j;
      }
    }
    //swap
    temp = arr[i];
    arr[i] = arr[min_element];
    arr[min_element] = temp;
  }
}
```

## bubble sort

> repeatedly swapping the adjacent elements if they are in wrong order

### Pseudocode

- Loop $i: 0 \rightarrow n - 1$
	- Loop $j: 0 \rightarrow (n-i-1)$
		- if `arr[j] > arr[j+1]`
			- swap arr[j] , arr[j+1]

### Code

```cpp
void bubble_sort(int *arr, int n) {
  int temp;

  for(int i=0;i<n-1;i++) {
    for(int j=0;j<n-i-1;j++) {
      if(arr[j] > arr[j+1]) {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}
```

## Optimized Bubble Sort

> The above function always runs $O(n^2)$ time even if the array is sorted. It can be optimized by stopping the algorithm if inner loop didn’t cause any swap.

### Pseudocode

- `swapped` bool variable
- Loop $i: 0 \rightarrow n - 1$
	- swapped = false
	- Loop $j: 0 \rightarrow (n-i-1)$
		- if `arr[j] > arr[j+1]`
			- swap arr[j] , arr[j+1]
			- swapped = true
	- if not swapped
		- break

### Code

```cpp
void bubble_sort(int *arr, int n) {
  int temp;
  bool swapped;

  for(int i=0;i<n-1;i++) {
    swapped = false;

    for(int j=0;j<n-i-1;j++){
      if(arr[j] > arr[j+1]){
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
        swapped = true;
      }
    }

    if(!swapped)
      break;
  }
}
```

## Insertion Sort

> The array is virtually split into a sorted and an unsorted part. Values from the unsorted part are picked and placed at the correct position in the sorted part.

- Time Complexity: $O(n^2)$
- Auxiliary Space: $O(1)$

### Pseudocode

- Loop $i:1 \rightarrow n$
	- `j = i - 1`
	- `key = arr[i]`
	- Loop `j >= 0` and `arr[j] > key`
		- `arr[j+1] = arr[j]`
		- `j = j - 1`
	- `arr[j+1] = key`

### Code

```cpp
void insertion_sort(int *arr, int n) {
  int j = 0, key;

  for(int i=1;i<n;i++) {
    j = i - 1;
    key = arr[i];

    while(j>=0 && arr[j] > key){
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = key;
  }
}
```

## Merge Sort

>  It divides the input array into two halves, calls itself for the two halves, and then merges the two sorted halves. The merge() function is used for merging two halves. The `merge(arr, l, m, r)` is a key process that assumes that arr[l..m] and arr[m+1..r] are sorted and merges the two sorted sub-arrays into one.

- follows `divide and conquer`