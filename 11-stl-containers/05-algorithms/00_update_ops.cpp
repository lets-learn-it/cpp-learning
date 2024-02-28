#include <iostream>
#include <algorithm>
#include <vector>

#define printa(x,n) for(int i=0;i<n;i++) std::cerr<<x[i]<<" "; std::cerr<<std::endl;

int main() {
  int arr1[] = {1,2,3,4,5,6};
  std::vector<int> arr2 = {1,2,3,4,5,6};

  printa(arr1, 6);

  // square first 3 numbers;
  std::for_each(arr1, arr1+3, [](int &x) { x *= x; });
  printa(arr1, 6);

  // multiply whole array by 2
  std::for_each(arr2.begin(), arr2.end(), [](int &x) { x *= 2; });
  printa(arr2, 6);

  // Transform
  // put output in same array
  std::transform(arr2.begin(), arr2.end(), arr2.begin(), [](const int& n) { return n*n; });
  printa(arr2, 6);

  // put output in another collection
  std::transform(arr1, arr1+6, arr2.begin(), [](const int& n){return n*n*n;});
  printa(arr1, 6);
  printa(arr2, 6);


  return 0;
}