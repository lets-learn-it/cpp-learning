# Smart Pointers

- enable automatic, exception-safe, object lifetime management
- **Pointer Categories**
  - `unique_ptr`: unique object ownership
  - `shared_ptr`: shared object ownership
  - `weak_ptr`: weak reference to an object managed by `shared_ptr`

```cpp
// Sample Class
class Entity {
private:
  int a;
public:
  Entity (int num) {
    this->a = num;
    std::cout << "Creating Object " << a << std::endl;
  }
  ~Entity () {
    std::cout << "Destroying Object " << this->a << std::endl;
  }
};
```

## `unique_ptr`

```cpp
// create
std::unique_ptr<Entity> i(new Entity(56));
std::unique_ptr<Entity> j{new Entity(75)};
std::unique_ptr<Entity> k = std::make_unique<Entity>(25);
```

## `shared_ptr`

- It retains shared ownership of an object through a pointer. Several shared_ptr objects may own the same object.

## `weak_ptr`


## References

[[00] https://en.cppreference.com/w/cpp/memory](https://en.cppreference.com/w/cpp/memory)
