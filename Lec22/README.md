## big 3 (memory management for classes)

1. copy assignment operator
   - delete the callee content
     - (p.33: loop thru the vector, delete each box or delete the vecror)
   - deep copy from OTHER to this
     - loop thru OTHER, and add this to this.vector
2. copy constructor (copy the exact same logic from step 2 of copy assignment)
3. destructor (handle cleanup) (copy the exact same logic from step 1 of copy assignment) (`~Warehouse()`)

- when the destructor will be called?
- object lifecycle

### operator overloading

function overloading (ftn with same name, different prarams)

```c++
// free function (typically in header file)
std::ostream& operator<<(
std::ostream&, const Warehouse&
);
```

## Assignment, deep, shallow copy

- shallow copy point to the same memory address
- deep copy having two different memory addresses, but exactly same content

##
