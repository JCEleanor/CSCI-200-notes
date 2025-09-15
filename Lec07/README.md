- DRY (Don't Repeat Yourself)
- function should adhere to SOLID
- WORM (Write Only Read Many)

- to define a function, first thing we need to do is to define an interface
- functions in C++ are in lower snake case i.e. `compute_value`

```c++
// this is function header (what's inside is the function body)
/**
 * @brief
 *
 * @param length
 * @param width
 * @param height
 * @return int
 */
int compute_value(int length, int width, int height)
{
    int value = length * width * height;
    return value;
}
```

- doxgengen is a documentation tool (sort of like jsdoc). In this class, we need to write doc for every function
- arguments v. parameters
- pass by value will always make copies. For example, when we pass in a, b and c into the function compute_value, the value will be copy inside the scope of compute_value, and then do something, but the actual value of a, b, and c will not change.

- pass by reference
