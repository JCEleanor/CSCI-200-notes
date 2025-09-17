### Overloading Functions

- functions with same name but expect different params (number of params or data types)
- in the future we will look at overloading operators and many overloading functions use cases

```c++
int func(int x, double y) { return 1; }
int func(double x, int y) { return 2; }
```

### Function Scope

- c++ doesn't erase memory when its out of scope. stack memory does not get cleared out
- free store / heap

### Pointers

- functions and variables are stored as an adress
- Clockwise winding order resolution
- `float** e`; a pointer to a pointer to a float

  <br/>

- <b>value of a pointer is an adress</b>
- <b>value pointed at is the value i set</b>
