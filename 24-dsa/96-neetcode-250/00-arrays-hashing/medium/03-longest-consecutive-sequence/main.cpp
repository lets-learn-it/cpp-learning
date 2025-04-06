#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> us;
    unordered_set<int> checked;
    int ans = 0, n = nums.size();

    for (int i = 0; i < n; i++) {
      us.insert(nums[i]);
    }

    for (int i = 0; i < n; i++) {
      if (us.find(nums[i] - 1) == us.end() &&
          checked.find(nums[i]) == checked.end()) {
        checked.insert(nums[i]);
        int j;
        for (j = nums[i]; us.find(j) != us.end(); j++) {
        }
        ans = max(ans, j - nums[i]);
      }
    }

    return ans;
  }
};