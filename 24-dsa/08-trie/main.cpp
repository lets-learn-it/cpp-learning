#include "trie.hpp"
#include <iostream>

int main() {
  Trie t;
  t.insert("apple");
  t.insert("app");
  t.insert("application");
  t.insert("banana");
  t.insert("bottle");
  t.insert("bottle");

  auto words = t.all_words();
  for (auto word: words) {
    std::cout << word << std::endl;
  }

  // search for
  std::cout << "Searching for bucket: " << t.search("bucket") << std::endl;
  std::cout << "Searching for bottle: " << t.search("bottle") << std::endl;

  // search all with prefix app
  auto matches = t.starts_with("app");
  for (auto word: matches) {
    std::cout << word << std::endl;
  }
}
