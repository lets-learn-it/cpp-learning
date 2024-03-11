#include <iostream>
#include <variant>
#include <vector>

/*
 * https://medium.com/@nerudaj/std-visit-is-awesome-heres-why-f183f6437932
 *
 */

struct NodeA {};
struct NodeB {};
struct NodeC {};

using number = std::variant<int, float, double>;
using Node = std::variant<NodeA, NodeB, NodeC>;

struct Visitor {
  void operator() (const int& a) { std::cout << "int: " << a << std::endl; }
  void operator() (const float& a) { std::cout << "float: " << a << std::endl; }
  void operator() (const double& a) { std::cout << "double: " << a << std::endl; }
};

struct NodeVisitor {
  void operator() (const NodeA& a) { std::cout << "NodeA" << std::endl; }
  void operator() (const NodeB& a) { std::cout << "NodeB" << std::endl; }
  void operator() (const NodeC& a) { std::cout << "NodeC" << std::endl; }
};

int main() {
  std::vector<number> nums = {1, 2, 3.14, (float) 3.14};

  for (auto&& num : nums) {
    std::visit(Visitor{}, num);
  }

  std::vector<Node> nodes = {
    NodeA{},
    NodeB{},
    NodeA{},
    NodeC{}
  };

  for (auto&& node : nodes) {
    std::visit(NodeVisitor{}, node);
  }

  return 0;
}