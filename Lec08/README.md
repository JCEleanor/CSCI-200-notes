- declare a function at the beginning and then define the functon at the bottom (not a good way)

  - linker error might show if one forgets to add implementation (i.e., you decalre the functionup front, but not defined)

- Two ways to declare the functions:

```c++
double add(double, double);

// best practice
double add(const double LHS, const double RHS);

```

- to seperate files, we have a header file (came from c?) and main.cpp

- Header guard:

```
#ifndef MATH_FUNCTION_H
#define MATH_FUNCTION_H

#endif
```
