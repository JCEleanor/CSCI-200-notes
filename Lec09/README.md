### Overloading Functions

- functions with same name but expect different params (number of params or data types)
- in the future we will look at overloading operators and many overloading functions use cases

```c++
int func(int x, double y) { return 1; }
int func(double x, int y) { return 2; }
```

- functions can't only differ in return type. For example the below code will have compiler error:

```c++
int func(int x, double y) { return 1; }
char func(int x, double y) { return '2'; }
```

### Function Scope

#### Call stack

Storage for varaibles known at compile time.

- each function call appends to the stack (a stack frame)

  - address of execution (file and line number)
  - local variables (include parameters)

- c++ doesn't erase memory when its out of scope. stack memory does not get cleared out
- free store / heap

#### Free Store (heap)

Pool of unused memory for dynamic memory.

Use pointer to store value on the free store.

### Pointers

#### **Pointer denoted by\* **

#### **Value of pointer is a memory address**

#### **Value pointed at is the data stored at that memory address**

if a pointer is initialized to be null, it's value is possibly `0x0`

- functions and variables are stored as an address
- Clockwise winding order resolution

A mnemonic (a memory aid) called "clockwise/spiral" rule for reading complex c++ declaration.
You start at the indentifier (the variable name) and spiral your way out in a clockwise direction.

- `float** e`; a pointer to a pointer to a float

```c++
float* x;
// y is a pointer to a float* (a pointer to a float pointer)
// the value store in y is the memory address of another pointer, which in turns points to a float
float** y;
// z as a pointer to a function. The parenthesis is the key.
// z is a pointer that points to a function that takes two int and return int
int (*z) (int, int);
```

  <br/>

- <b>value of a pointer is an address</b>
- <b>value pointed at is the value i set</b>

#### `NULL` VS. `nullptr`

```c++
void foo(int x){}
void foo(int *px){}

int main(){
  // x has a value of 0
  int x = NULL;

  // px has a value of 0
  int *px = NULL;

  // error: cannot convert nullptr_t to int
  int y = nullptr;

  // py has a value of 0x0
  int *py  = nullptr;

  // error: ambiguous call to foo(int) or foo(int*)
  foo(NULL);

  // call foo(int*)
  foo(nullptr);

  return 0;
}
```
