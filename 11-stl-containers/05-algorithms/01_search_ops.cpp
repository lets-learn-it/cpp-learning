#include <iostream>
#include <algorithm>
#include <vector>

int main() {
  int evens[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
  int odds[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
  int even_odds[] = {1,2,3,4,5,6};

  std::cout << std::find(evens, evens+10, 4) << std::endl;

  // check if array has all even numbers
  std::cout << std::all_of(evens, evens+10, [](int x) -> bool { return x%2 == 0; }) << std::endl;

  // check if non element in array is even
  std::cout << std::none_of(odds, odds+10, [](int x) -> bool { return x%2 == 0; }) << std::endl;

  // check if any element in array is even
  std::cout << std::any_of(even_odds, even_odds+6, [](int x) { return x%2 == 0; }) << std::endl;
  std::cout << std::any_of(odds, odds+10, [](int x) -> bool { return x%2 == 0; }) << std::endl;

  std::vector<int> arr = {1,2,3,2,5,2,6,4,2,1};

  // count number of occurences
  std::cout << std::count(arr.begin(), arr.end(), 2) << std::endl;

  // finding min_element, max_element, and minmax_element
  std::cout << *std::min_element(arr.begin(), arr.end()) << std::endl;
  std::cout << *std::max(arr.begin(), arr.end()) << std::endl;

  std::pair<std::vector<int>::iterator, std::vector<int>::iterator> minmax = std::minmax_element(arr.begin(), arr.end());
  std::cout << *minmax.first << " " << *minmax.second << std::endl;
  return 0;
}