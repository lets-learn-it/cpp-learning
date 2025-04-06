#include <map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> m;
    vector<int> ans = {0, 0};

    for (int i = 0; i < nums.size(); i++) {
      if (auto f = m.find(target - nums[i]); f != m.end()) {
        ans[0] = i;
        ans[1] = f->second;
        return ans;
      }
      m[nums[i]] = i;
    }
    return ans;
  }
};
