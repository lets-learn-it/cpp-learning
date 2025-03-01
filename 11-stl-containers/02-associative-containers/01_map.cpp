#include <iostream>
#include <map>
#include <string>
#include <tuple>

/*
 * std::map is sorted associative container that contains key-value pairs with unique keys
 * Keys are sorted by using comparision function Compare.
 *
 * Search, removal and insertion operations have logarithmic complexity.
 * Usually implemented as Red-Black trees.
 *
 */

template<typename T1, typename T2>
void print_map(const char *message, std::map<T1, T2> &s) {
  std::cout << message << ": ";
  for(auto& [k, v] : s) {
    std::cout << "{ " << k << ": " << v << " } ";
  }
  std::cout << std::endl;
}

int main() {
  std::map<std::string, std::string> people{{"Parikshit", "I am 26"}, {"XYZ", "I dont exist"}};
  print_map("people", people);

  // insert
  people.insert({"PQR", "I am PQR"});
  people["Parikshit"] = "XXX";

  print_map("people", people);

  // check if key exists of not
  if (auto f = people.find("Parikshit1"); f != people.end()) {
    std::cout << "exist\n";
  }

  // using exception
  try {
    auto x = people.at("Parikshit1");
    std::cout << "exist\n";
  } catch (std::out_of_range e) {
    std::cout << "does not exist\n";
  }

  // using count
  if (people.count("Parikshit") > 0) {
    std::cout << "Parikshit exists\n";
  }

  // access elements
  std::cout << "Parikshit >> " << people["Parikshit"] << std::endl;
  auto& ref = people["Parikshit1"];
  std::cout << "Parikshit >> " << people["Parikshit1"] << std::endl;
  ref = "Hi";
  std::cout << "Parikshit >> " << people["Parikshit1"] << std::endl;

  std::cout << "Parikshit >> " << people.at("Parikshit") << std::endl;
  try {
    std::cout << "Parikshit >> " << people.at("Parikshit1") << std::endl;
  } catch(std::out_of_range e) {
    std::cout << e.what() << std::endl;
  }

  // remove elements
  people.erase("Parikshit");   // exits
  people.erase("Parikshit1");  // does not

  print_map("people", people);
  return 0;
}