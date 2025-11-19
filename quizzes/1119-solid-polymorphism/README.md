## Base Code for All the Questions

### Q2

Result: `A::foo()`

```c++
class A {
public:
  virtual void foo() const { cout << "A::foo()"; }
  virtual void bar() const { cout << "A::bar()"; }
protected:
  virtual void baz() const { cout << "A::baz()"; }
private:
  virtual void qux() const { cout << "A::qux()"; }
};

class B final : public A {
public:
  void foo() const override { cout << "B::foo()"; }
  void bar() const override { cout << "B::bar()"; }
};

A obj = B();
obj.foo();
```

**Object slicing** (noted in Question 7).

### Q4

Result: Compilation Error. The order in class B is wrong.

```c++
class A {
public:
  virtual void foo() const { cout << "A::foo()"; }
  virtual void bar() const { cout << "A::bar()"; }
protected:
  virtual void baz() const { cout << "A::baz()"; }
private:
  virtual void qux() const { cout << "A::qux()"; }
};

class B final : public A {
public:
  void foo() override const { cout << "B::foo()"; }
  void bar() override const { cout << "B::bar()"; }
};

A* pObj = new B();
pObj->bar();
```

This is wrong:

```c++
  void foo() override const { cout << "B::foo()"; }
  void bar() override const { cout << "B::bar()"; }
```

The correct order is:

```c++
void foo() const override { ... }
void bar() const override { ... }
```

_OMG this is too evil._

### Q5

Result: Compilation Error. (cannot access member function)

```c++
class A {
public:
  virtual void foo() const { cout << "A::foo()"; }
  virtual void bar() const { cout << "A::bar()"; }
protected:
  virtual void baz() const { cout << "A::baz()"; }
private:
  virtual void qux() const { cout << "A::qux()"; }
};

class B final : public A {
public:
  void foo() const override { cout << "B::foo()"; }
  void bar() const override { cout << "B::bar()"; }
};

A* pObj = new A();
pObj->baz();
```

- Access Modifiers

  - `public`: Can be called by anyone, anywhere (e.g., inside main()).

  - `protected`: Can only be called by:

    - The class itself (A).

    - Classes that inherit from it (B).

    - "`Friend`" classes or functions.

  - `private`: Can only be called by the class itself (A).

### Q6

```c++
class A {
public:
  virtual void foo() const = 0;
  virtual void bar() const = 0;
protected:
  virtual void baz() const { cout << "A::baz()"; }
private:
  virtual void qux() const { cout << "A::qux()"; }
};

class B final : public A {
public:
  void foo() const override { cout << "B::foo()"; }
  void bar() const override { cout << "B::bar()"; }
};

A obj = B();
obj.bar();
```

Result: will result in a Compilation Error.

The `= 0` syntax marks A as a **Pure Virtual Function**

`A obj = B();`: the compiler tries to allocate memory for a standalone `A` object, but since `A` is an **abstract class**, the compiler forbids this and will throw an error like: "Variable type 'A' is an abstract class".

### Q7

```c++
class A {
public:
    virtual void foo() const { cout << "A::foo()"; }
    virtual void bar() const { cout << "A::bar()"; }
protected:
    virtual void baz() const { cout << "A::baz()"; }
private:
    virtual void qux() const { cout << "A::qux()"; }
};

class B final : public A {
public:
    void foo() const override { cout << "B::foo()"; }
    void bar() const override { cout << "B::bar()"; }
};

// object slicing
A obj = B();

// subtype polymorphism
A* pObj = new B();
```

#### Breakdown

The code demonstrates that a derived class (B) can be substituted where a base class (A) is expected. This property is called Polymorphism.

##### `A obj = B();`

- Create a temporary object of type `B`, but then **only copy** the `A` portion of the data into the variable `obj`

- While this technically relies on the inheritance relationship to compile (allowing a B to be converted to an A), it results in **Object Slicing**.

- why slicing? when you force `B` object into a variable designed only to hold an `A` object, the compiler **slices off** everything that makes B unique to fit it into `A`

  - what is lost?

    - the identity: **virtual table pointer**. Every object with virtual functions has a hidden pointer (vptr) inside it that points to a "lookup table" telling the program which function to run.

    The `B` object has a vptr that points to `B::foo()`.

    The `A` variable `obj` has a vptr that points to `A::foo()`.

    When you copy `B` into `obj`, **C++ does not copy the vptr**.

    - Extra Member Variables (If any)

- If you call `obj.foo()`, it will print `A::foo()` because obj is literally just an instance of A. It has lost its polymorphic behavior.

##### `A* pObj = new B();`

- subtype polymorphism: create a new instance of `B` but store its address in a pointer type of `A`
- this is **upcasting**. If call `pObj->foo()`, the program will look at the actual object type at runtime (dynamic dispatch) and print `B::foo()`

###
