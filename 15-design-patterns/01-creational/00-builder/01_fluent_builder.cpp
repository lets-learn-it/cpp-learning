#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class HtmlElement {
private:
  std::string name, text;
  std::vector<HtmlElement> elements;
  const size_t indent_size = 2;
public:
  HtmlElement() {}
  HtmlElement(const std::string &name, const std::string &text) : name(name), text(text) {}

  void set_name(std::string name) {
    this->name = name;
  }

  void add_child(HtmlElement &e) {
    this->elements.push_back(e);
  }

  std::string str(int indent=0) const {
    std::ostringstream oss;
    std::string i(indent_size*indent, ' ');
    oss << i << "<" << name << ">" << std::endl;
    if (text.size() > 0)
      oss << std::string(indent_size*(indent+1), ' ') << text << std::endl;
    for (const auto& e : elements)
      oss << e.str(indent + 1);
    oss << i << "</" << name << ">" << std::endl;
    return oss.str();
  }
};

class HtmlBuilder {
private:
  HtmlElement root;
public:
  HtmlBuilder(std::string root_name) {
    root.set_name(root_name);
  }

  HtmlBuilder& add_child(std::string child_name, std::string child_text) {
    HtmlElement e{child_name, child_text};
    root.add_child(e);
    return *this;
  }

  std::string str() const {
    return root.str();
  }

  static HtmlBuilder build(std::string root) {
    return HtmlBuilder{root};
  }
};

int main() {
  auto builder = HtmlBuilder::build("ul").add_child("li", "hi")
    .add_child("li", "hello");

  std::cout << builder.str() << std::endl;
  return 0;
}