#include <string>
using namespace std;

class Solution {
 public:
  bool isAnagram(string s, string t) {
    int times[26] = {0};

    for (char c : s) {
      times[c - 'a'] += 1;
    }

    for (char c : t) {
      times[c - 'a'] -= 1;
    }

    for (int i = 0; i < 26; i++) {
      if (times[i] != 0) return false;
    }

    return true;
  }
};
