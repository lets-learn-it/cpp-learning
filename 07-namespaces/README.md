# Namespace

- **Namespace** is provided to directly represent the notion of a set of facilities that directly belong together.
- The members of a namespace are in the same scope and can refer to each other without special notation, whereas access from outside the namespace requires explicit notation.
- member can be declared within namespace definition and defined later using `namespace-name::member-name` notation
  ```cpp
  // declaration
  namespace Parser {
    double expr(bool);
  }

  // definition
  double Parser::expr(bool b) {

  }
  ```
- Global scope is also namespace and can be explicitly referred to using `::`.
  ```cpp
  int f();  // global function

  int g() {
    int f;
    ::f();   // calling global function not variable.
  }
  ```
- `using`: When name is frequently used outside its namespace, it can be a bother to repeatedly qualify it with its namespace name. `using` declaration introduces synonym into a scope.
  ```cpp
  using std::string;

  std::vector<string> split(const string& s) {

  }
  ```
  When used for an overloaded name, a `using` declaration applies to all overloaded versions.
  ```cpp
  namespace N {
    // overloaded functions
    void f(int);
    void f(string);
  }

  void g() {
    using N::f;
    // both functions are available
    f(87);
    f("abc");
  }
  ```
- `using namespace`: It makes names from a namespace available almost as if they had been declared outside their namespace.
  ```cpp
  using namespace std;
  ```
- **namespace is open**. that is you can add names to it from several separate namespace declarations. That way, the members of namespace need not be placed contiguously in a single file.
  ```cpp
  // adding function to std namespace
  namespace std {
    void func();
  }
  ```
