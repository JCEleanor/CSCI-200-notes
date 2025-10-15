- const is modifying the datatype (could place in front of or behind the datatype) Typically ahead of the datatype
- compiler error if try to change constant value

### pointer modifier

```c++
const float * pPI= new float(3.14f);
float * const pPI= new float(3.14f);
const float * const P_PI= new float(3.14f);
```

### functions with const

apply to parameter or return type

- getter (in a class) in general will be marked `const` (bc they won't change the instance)

- callee and caller in a function
- constant function: can't change memeber data

### this

`this` is a pointer to the callee (to self)

you mark a functoin const unless it doesn't have a reason to not mark
