#include <string>
#include <vector>
#include <stack>
#include <utility>

struct TrieNode {
  TrieNode *next[26] = {nullptr};
  bool end = false;
};


class Trie {
private:
  TrieNode* root;

  void cleanup(TrieNode* node) {
    for (auto n: node->next) {
      if (n != nullptr) {
        cleanup(n);
      }
    }
    delete node;
  }

public:
  Trie() {
    root = new TrieNode();
  }
  ~Trie() {
    cleanup(root);
  }

  void insert(std::string word) {
    TrieNode* node = root;
    for (int i=0; i<word.length(); i++) {
      int index = word[i] - 'a';
      if (node->next[index] == nullptr) {
        node->next[index] = new TrieNode();
      }
      node = node->next[index];
    }
    node->end = true;
  }

  bool search(std::string word) {
    TrieNode* node = root;
    for (int i=0; i<word.length(); i++) {
      int index = word[i] - 'a';
      if (node->next[index] == nullptr) {
        return false;
      }
      node = node->next[index];
    }
    return node->end;
  }

  std::vector<std::string> starts_with(std::string prefix) {
    TrieNode* node = root;
    for (int i=0; i<prefix.length(); i++) {
      int index = prefix[i] - 'a';
      if (node->next[index] == nullptr) {
        return {};
      }
      node = node->next[index];
    }

    // do recursive search for all words in trie
    std::vector<std::string> words;
    starts_with_helper(node, prefix, words);
    return words;
  }

  std::vector<std::string> all_words() {
    std::vector<std::string> words;
    starts_with_helper(root, "", words);
    return words;
  }

  static void starts_with_helper(TrieNode* node, std::string s, std::vector<std::string>& words) {
    if (node->end) words.push_back(s);

    for (int i=0; i<26; i++) {
      if (node->next[i] != nullptr) {
        starts_with_helper(node->next[i], s + (char)('a' + i), words);
      }
    }
  }
};
