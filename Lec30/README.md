### Pure virtual functions

### Abstract class

Class with at least one abstract function is
an Abstract Class

```c++
class Animal {
public:
virtual ~Animal() {}
virtual void speak() const = 0; // abstract declaration
}
```

### Interface

An interface is like abstract class with only abstract functions. No data members.

```c++
template<typename T>
class IList {
public:
// C++ requires a virtual destructor be present
// the virtual keyword is there so when we call destructor on the parent class, it will also clean the child class
virtual ~IList() {}

virtual void pushFront(T) = 0;
virtual void pushBack(T) = 0;
virtual T popFront() = 0;
virtual T popBack() = 0;
virtual void insert(int, T) = 0;
virtual T remove(int) = 0;
virtual unsigned int size() const = 0;
virtual T& at(int) = 0;
virtual void set(int, T) = 0;
// ...
};
```

### Design principle

overarching design principle: program to an interface, mot an implememtation

#### Interface Segregation principle

clients (subclasses) should not be forced to depend on interface they do not use.
