# Asynchronous Programming

## `std::packaged_task`

- It associates a function with an `std::promise`
- it represents an asynchronous operation
- It is callable object. When called, function is run and its return value is stored in promise and can get from associated future.
- Useful for managing threads
  - Each task can be run on specified thread
  - Thread pool consists of threads waiting for work to arrive

## `std::async`

- we can start thread by calling `std::async()`
- `async()` represents a higher level abstraction than `std::thread`
