# Design Patterns

## Dynamic Binding

- Run time association of request to an object and one of its operations is known as dynamic binding.
- It means that issuing a request doesn't commit you to a particular implementation until run-time.

## Class Vs Interface inheritance

- *Class inheritance* defines an object's implemenation in terms of another object's implementation. In short, its mechanism for code & representation sharing.
- *Inferface inheritance* or subtyping describes when an object can be used in place of another. (Both implement same interface)
>Programming to an interface, not an implementation
- Benefits to manupulating objects solely in terms of interface define by abstract classes.
  - Clients remain unaware of the specific types of objects they use, as long as the objects adhere to the interface that clients expect.
  - Clients remain unaware of the classes that implement these objects. Clients only know about abstract classes defining interface.

## Inheritance Vs Composition

- *Class inheritance* lets you define the implementation of one class in terms of another's (reuse by subclassing). Internals of parent classess are often visible to subclasses.
  - **Advantages**
    - It is defined statically at compile time
    - Easier to modify implementation being reused (override parent methods)
  - **Disadvantages**
    - Can't change implementation at run-time as its defined at compile time.
    - It exposes a subclass to details of its parent's implementation. (breaks encapsulation)
    - Change in parent's implementation may force subclasses's to change.
- In *object composition*, new functionality is obtained by assembling or composing objects to get more complex functionality. It requires that objects being composed have well defined interfaces. No internals are visible.
  - **Advantages**
    - defined dynamically at run-time through objects acquiring references to other objects.
    - Implementation can be swapped without chaning client with object which implements same interface.
    - Objects are accessed using only interfaces, encapsulation isn't broken.
    - class hierarchies will remain small.
  - **Disadvantages**
    - Can be less efficient.
>Favor object composition over class inheritance.



## References

[00] Design Patterns - Elements of reusable object oriented software

[[01] https://www.udemy.com/course/patterns-cplusplus/](https://www.udemy.com/course/patterns-cplusplus/)

[[02] Design Patterns in Modern C++ - udemy.com](https://www.udemy.com/course/patterns-cplusplus/)
