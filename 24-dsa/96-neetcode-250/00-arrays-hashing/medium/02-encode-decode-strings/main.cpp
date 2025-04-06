#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string encode(vector<string> &strs) {
    int n = strs.size();
    int reqSize = n * 4;

    for (int i = 0; i < n; i++) {
      reqSize += strs[i].size();
    }

    char buff[reqSize + 1];
    int pos = 0;

    for (int i = 0; i < n; i++) {
      int strSize = strs[i].size();
      memcpy(buff + pos, &strSize, 4);
      pos += 4;
      memcpy(buff + pos, strs[i].c_str(), strSize);
      pos += strSize;
    }

    return string(buff, pos);
  }

  vector<string> decode(string &str) {
    char *buff = str.data();
    int pos = 0, strSize;
    vector<string> vs;

    while (pos < str.size()) {
      memcpy(&strSize, buff + pos, 4);
      pos += 4;
      char ss[strSize + 1];
      memcpy(ss, buff + pos, strSize);
      pos += strSize;
      ss[strSize] = '\0';
      vs.push_back(string(ss));
    }

    return vs;
  }
};

int main() {
  Solution sol;

  vector<string> strVec = {"hello", "there", "What's", "Up:", "!"};

  string str = sol.encode(strVec);
  vector<string> ans = sol.decode(str);

  for (string &s : ans) {
    cout << s << endl;
  }

  return 0;
}