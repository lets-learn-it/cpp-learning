#include <iostream>

#define printArray(arr, n) for(int i=0;i<n;i++) printf("%d ", arr[i]); printf("\n");

int* generate1(int n);

int main() {
  int* arr;
  int n = 10;

  arr = generate1(n);

  printArray(arr, n);

  return 0;
}

int* generate1(int n) {
  // need to allocate memory on heap & not stack
  int *arr = new int[n];

  for (int i = 0; i < n; i++) {
    arr[i] = i;
  }
  
  return arr;
}