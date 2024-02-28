#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

int main() {
  auto print_int = [](const int& n) { std::cout << n << " "; };
  std::set<int> s1, s2;

  s1 = {3,4,8,4,5};
  s2 = {1,2,6,3,4};

  std::for_each(s1.begin(), s1.end(), print_int); std::cout << std::endl;
  std::for_each(s2.begin(), s2.end(), print_int); std::cout << std::endl;

  std::vector<int> out;
  std::set<int> dst;

  // union of s1 and s2
  std::set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), std::back_inserter(out));
  std::for_each(out.begin(), out.end(), print_int);
  std::cout << std::endl;

  // intersection of s1 and s2
  std::set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(dst, dst.begin()));
  std::set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), std::insert_iterator<std::set<int>>(dst, dst.begin()));
  std::for_each(dst.begin(), dst.end(), print_int);
  std::cout << std::endl;

  // difference of s1 and s2
  out.clear();
  std::set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), std::back_inserter(out));
  std::for_each(out.begin(), out.end(), print_int);
  std::cout << std::endl;

  // symmetric difference of s1 and s2
  out.clear();
  std::set_symmetric_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), std::back_inserter(out));
  std::for_each(out.begin(), out.end(), print_int);
  std::cout << std::endl;

  return 0;
}