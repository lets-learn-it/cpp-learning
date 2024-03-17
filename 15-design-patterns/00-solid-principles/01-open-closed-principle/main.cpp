#include <iostream>
#include <string>
#include <vector>

enum class Color { red, green, blue };
enum class Size { small, medium, large };

class Product {
private:
  std::string name;
  Color color;
  Size size;
public:
  Product(std::string name, Color c, Size s) : name(name), color(c), size(s){
    std::cout << "creating product" << std::endl;
  }

  Color get_color() {
    return color;
  }

  Size get_size() {
    return size;
  }

  std::string& get_name() {
    return name;
  }
};

// type declaration, we will define it later
template <typename T> class AndSpecification;

template <typename T>
class Specification {
public:
  virtual bool is_satisfied(T* item) const = 0;

  // compact version using operator && overloading
  AndSpecification<T> operator&&(Specification<T>& other) {
    return AndSpecification{*this, other};
  }
};

template <typename T>
class Filter {
public:
  virtual std::vector<T*> filter(std::vector<T*> items, Specification<T>& spec) = 0;
};

class BetterFilter : Filter<Product> {
public:
  std::vector<Product*> filter(std::vector<Product*> items, Specification<Product>& spec) override {
    std::vector<Product*> result;
    for (auto& item: items) {
      if (spec.is_satisfied(item)) {
        result.push_back(item);
      }
    }
    return result;
  }
};

class ColorSpecification : public Specification<Product> {
private:
  Color color;
public:
  ColorSpecification(Color color): color(color) {}
  bool is_satisfied(Product* item) const override {
    return item->get_color() == color;
  }
};

class SizeSpecification : public Specification<Product> {
private:
  Size size;
public:
  SizeSpecification(Size size): size(size) {}
  bool is_satisfied(Product* item) const override {
    return item->get_size() == size;
  }
};

template <typename T>
class AndSpecification : public Specification<T> {
private:
  Specification<T>& first;
  Specification<T>& second;
public:
  AndSpecification(Specification<T> &first, Specification<T> &second) : first(first), second(second) {
    std::cout << "creating and specification" << std::endl;
  }

  bool is_satisfied(T *item) const override {
    return first.is_satisfied(item) && second.is_satisfied(item);
  }
};

int main() {
  Product apple{"Apple", Color::green, Size::small};
  Product tree{"Tree", Color::green, Size::large};
  Product house{"House", Color::blue, Size::large};

  std::vector<Product*> items {&apple, &tree, &house};

  BetterFilter bf;
  ColorSpecification greenSpec{Color::green};

  for (auto i: bf.filter(items, greenSpec)) {
    std::cout << i->get_name() << std::endl;
  }

  ColorSpecification blue{Color::blue};
  SizeSpecification large{Size::large};

  AndSpecification<Product> andSpec{blue, large};

  for (auto i: bf.filter(items, andSpec)) {
    std::cout << i->get_name() << std::endl;
  }

  // compact version using operator overloading
  auto andSpec2 = blue && large;
  for (auto i: bf.filter(items, andSpec2)) {
    std::cout << i->get_name() << std::endl;
  }
  return 0;
}
