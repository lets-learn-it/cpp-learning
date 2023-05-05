# Synchronization

## Condition Variables

- Thread1 waits for condition variables.
- Thread2 completes its work and notifies condition variable
- condition variable wakes thread1
- `notify_all()`: all threads which have called `wait()` on condition variable to be woken up in any order at same time
- `notify_one()`: only & any one of the threads will be woken up. Other waiting threads will remain blocked.

## Condition Variables with Predicate

- avoids spurious and lost wake ups.
- avoid using condition variables and use condition variables with predicate.

## Futures and Promises

- `std::thread` does not provide way to return value from thread.
- for trasfering data between threads, we can use `std::future` and `std::promise`
- No explicit locking or shared data variable is required.
- futures and promises use a producer-consumer model


- future represent value that has not yet been computed.
- `std::future` is 
- `get()` member function obtains value when ready. blocks until operation is complete.
- other functions `wait()`, `wait_for()` and `wait_until()`

- we obtain future instance from promise by calling `get_future()` member function of promise. It will set up shared state.
- When consumer is ready to receive result, it calls future's `get()` member function.

