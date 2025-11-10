## SOLID: Program to an interface

SOLID priciples basically revolve around this concept

### Single Responsibility Principle

A class (or function) should have only one purpose.

### Open Close Principle

Classes/modules/functions should be open for extension but closed for modification.

- open (`virtual`): classes can be inherited from, interfaces can be implemented
- close (`final`): Can mark functions that cannot be
  overridden further as `final`
- `virtual` and `final`

```c++
class A {
public:
  virtual void foo() { }
  virtual void bar() final { } // can't be overriden
};

// Q: why virtual and final at the same time?
```

```c++
class A {
public:
  virtual void foo() { cout << "A::foo()" << endl; }
};
class B final : public A {
public:
  void foo() override { cout << "B::foo()" << endl; }
};
// class C : public B { // B cannot be inherited from
//                      // since it is closed
// };

```

- classes are open (`virtual`) by default

### Liskov Substitution Priciple

Object of the superclass can be replaced by objects of subclasses without breaking the application. In other words, **objects of the subclass behave in the same way as objects of the superclass**

For example, we want a vector of `Animal` instead of a vector of `Dog`, `Cat` or `Lion`.

- Overridden method needs to accept same input
  parameters. Cannot enforce stricter validation
  rules
- Overridden method needs to return same values.  
  Can be subclass or subset of valid values

#### A classic example

A _Square_ is a _Rectangle_

### Interface Segregation Principle

upon interfaces that they do not use.

### Dependency Inversion Principle

High-level modules should not depend on low-
level modules. Both should depend on
abstractions.

**If already following OCP and LSP, then DIP should already be enforced.**

## Designing for Abstraction

Favor composition over inheritance.

Example: A class that contains a pointer to specific `FlyBehavior` and `QuackBehavior`.
