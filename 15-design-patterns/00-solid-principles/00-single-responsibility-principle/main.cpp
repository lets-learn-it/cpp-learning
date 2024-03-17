#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Journal {
private:
  std::vector<std::string> entries;
  std::string title;
  int count;
public:
  Journal(const std::string& title) : title(title), count(1) {
    std::cout << "creating journal" << std::endl;
  }

  ~Journal() {
    std::cout << "destroying journal" << std::endl;
  }

  void add_entry(const std::string& entry) {
    entries.push_back(entry);
  }

  const std::vector<std::string>& get_entries() const {
    return entries;
  }
};

struct PerisistenceManager {
  static void save(const Journal& journal, const std::string& filename) {
    std::ofstream ofs(filename);
    for (auto& e: journal.get_entries())
      ofs << e << std::endl;
  }
};

int main() {
  Journal journal{"Dear Diary"};

  journal.add_entry("I ate a bug");
  journal.add_entry("I cried today");

  PerisistenceManager pm;
  pm.save(journal, "demo.txt");
  return 0;
}
