#include <algorithm>
#include <map>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    // unordered_map can give better performance
    map<string, vector<string>> hm;

    for (string s : strs) {
      string sCopy(s);
      sort(s.begin(), s.end());
      hm[s].push_back(sCopy);
    }

    vector<vector<string>> ans;
    for (auto h : hm) {
      ans.push_back(h.second);
    }
    return ans;
  }
};
