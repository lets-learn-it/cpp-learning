# Vocabulary Types

## pair

- [https://en.cppreference.com/w/cpp/utility/pair](https://en.cppreference.com/w/cpp/utility/pair)
- `std::pair` is a class template that provide a way to store two heterogeneous objects as a single unit

## tuple

- [https://en.cppreference.com/w/cpp/utility/tuple](https://en.cppreference.com/w/cpp/utility/tuple)
- `std::tuple` is class template  that provide fixed-sized collection of heterogeneous values.

## optional

- [https://en.cppreference.com/w/cpp/utility/optional](https://en.cppreference.com/w/cpp/utility/optional)
- It manages an optional/contained value. ie. a value that may or may not be present.
- common use case for optional is the return value of a function that may fail.
- any instance of `optional<T>` at any given point in time either contains a value of does not contain value.
If an `optional<T>` contains a value, the value is guaranteed to be allocated as part of the optional object footprint. ie. no dynamic memory allocation ever takes place.

## any

- [https://en.cppreference.com/w/cpp/utility/any](https://en.cppreference.com/w/cpp/utility/any)
- The class `any` describes a type-safe container for single values of any copy constructible type.

## variant

- [https://en.cppreference.com/w/cpp/utility/variant](https://en.cppreference.com/w/cpp/utility/variant)
- It represent type-safe `union`. Instance of `std::variant` at any given time either holds a value of one of its
  alternative types, or in case of error - no value.
- As with unions, if a variant holds a value of some object type `T`, it is put in variant itself. No memory allocated.
- It is not permitted to hold references, arrays or type `void`.
- **Disadvantages**:
  - Types need to be fully defined before they can be used in the variant. Storage size needs to be known.
  - Using types with vastly different sizes means that your variant will inherently waste a lot of space.

## expected c++23

**Make sure to install g++-12**

- [https://en.cppreference.com/w/cpp/utility/expected](https://en.cppreference.com/w/cpp/utility/expected)
- class template `std::expected` provies a way to store either of two values.
- An object of `std::expected` at any given time either holds an expected value of type `T` or an unexpected value of type `E` .
- **`std::expected` is never valueless**
- The stored value is allocated directly within the storage occupied by the expected object. No dynamic memory allocation takes place.
