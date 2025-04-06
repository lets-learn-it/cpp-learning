#include <string>
#include <vector>
using namespace std;

struct Node {
  Node* c[26] = {nullptr};
  bool end = false;
};

class Trie {
 private:
  Node* root = nullptr;

 public:
  Trie() { root = new Node; }

  void insert(std::string s) {
    Node* node = root;
    Node* tmp = nullptr;
    for (char c : s) {
      if (node->c[c - 'a'] == nullptr) {
        tmp = new Node;
        node->c[c - 'a'] = tmp;
      }
      node = node->c[c - 'a'];
    }
    node->end = true;
  }

  std::string prefix() {
    std::string s = "";
    Node* node = root;
    while (true) {
      int flag = 0;
      int ind;
      for (int i = 0; i < 26; i++) {
        if (node->c[i] != nullptr) {
          flag++;
          ind = i;
        }
      }
      if (flag != 1) {
        break;
      }
      s += ('a' + ind);
      node = node->c[ind];
      if (node->end) break;
    }
    return s;
  }
};

class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    Trie t;
    for (string s : strs) {
      if (s.size() == 0) return "";
      t.insert(s);
    }
    return t.prefix();
  }
};
