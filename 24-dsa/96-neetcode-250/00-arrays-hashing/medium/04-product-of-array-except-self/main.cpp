#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    int zeros = count(nums.begin(), nums.end(), 0);
    vector<int> ans(n, 0);

    if (zeros >= 2) {
      return ans;
    }

    int mult = 1;
    for (int i = 0; i < n; i++) {
      if (nums[i] != 0) {
        mult *= nums[i];
      }
    }

    for (int i = 0; i < n; i++) {
      if (zeros != 0 && nums[i] != 0) {
        ans[i] = 0;
      } else {
        if (nums[i] != 0)
          ans[i] = mult / nums[i];
        else
          ans[i] = mult;
      }
    }

    return ans;
  }
};
