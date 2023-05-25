#include <iostream>
#include <algorithm>
#include <vector>

struct Person {
  std::string name;
  int age;
};

struct CompareByAge {
  bool operator()(const Person& p1, const Person& p2) const {
    return p1.age < p2.age;
  }
};

int main() {
  std::vector<Person> people = {
    {"Alice", 25},
    {"Bob", 30},
    {"Charlie", 20}
  };

  std::sort(people.begin(), people.end(), CompareByAge());

  for (const auto& person : people) {
    std::cout << "Name: " << person.name << ", Age: " << person.age << std::endl;
  }

  return 0;
}
