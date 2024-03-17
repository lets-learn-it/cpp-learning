# Stream Operators

- stream insertion `<<` is used for output and extraction operator `>>` is used for input.
- `cout` is an object of `ostream` class & `cin` is an object of `istream` class.
- These operators (`<<` & `>>`) must be overloaded as **global function**. And **if we want to allow them to access private data members of class, we must make them `friend`**.
- It can't be class member function, you have to make it friend function of your class.

## Why these operators must be overloaded as global/friend functions?

- In operator overloading, if an operator is overloaded as a member, then it must be a member of the object on the left side of the operator.
- Suppose `+` is overloaded by some class then `o1` & `o2` can use it like `o1 + o2`. Now funtion of `o1` will get called (first one).
- The operators `<<` and `>>` are called like `cout << o1` and `cin >> o1`. Means classes of `cout` & `cin` should have functions. Therefore, these operators are overloaded as global functions with two parameters, `cout` and object of user-defined class.
- When we call method of class like `obj.method(...)`, it gets converted like `class::method(obj& this, ...)`. Which means when we define `std::ostream& operator << (std::ostream& output, Test& obj)` will gets called when `cout << obj`

## References

[[00] Overloading stream insertion (<>) operators in C++ - geeksforgeeks.org](https://www.geeksforgeeks.org/overloading-stream-insertion-operators-c/)

[[01] Stream Insertion | Stream Extraction Operator Overloading In C++ - youtube.com](https://www.youtube.com/watch?v=2972LRdyquk)
