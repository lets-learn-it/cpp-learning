# Builder

- separate the construction of complex object from its representation so that the same construction process can create different representations.

## Motivation

- Some objects are simple and can be created in a single constructor call. Other objects require lot of ceremony to create
- Having an object with 10 constructor arguments is not productive
- Instead, opt for piecewise construction
- Builder provides an API for constructing an object step-by-step.
