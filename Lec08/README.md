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

- if run `makd depend`, it will add dependencies automatically to the Makefile

```
# DEPENDENCIES
main.o: main.cpp math_funcions.h
math_funcions.o: math_funcions.cpp math_funcions.h
```

- if run `make`, it will build all the independent files. Example output:

```
g++ -std=c++17 -g -Wall -Wextra -Wconversion -Wdouble-promotion -Wunreachable-code -Wshadow -Wpedantic -o main.o -c main.cpp
g++ -std=c++17 -g -Wall -Wextra -Wconversion -Wdouble-promotion -Wunreachable-code -Wshadow -Wpedantic -o math_funcions.o -c math_funcions.cpp
g++ -o Lec08 main.o math_funcions.o
```

- develop process: defined functions in header files, implement the logic in the \*.cpp file, and use the functions in main.cpp

- function declaration (prototype)
  it's a promise to the compiler that this function with this name, return type and parameters exists somewhere.

```c++
int add (int a, int b);

```

- function definition
  The actual implementation of a function.

```c++
int add (int a, int b){
  return a + b;
}

```

In C and C++, a function signature or function prototype declared within a header file provides the compiler with essential information about a function without including its full implementation
