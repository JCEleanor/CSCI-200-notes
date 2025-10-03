- `&` address-of operator (getting the address of a variable)
- `*` dereference operator (getting the value of a pointer)

```c++
double *ptr = new double; // carve out 8 byte of memory for address of ptr

cout << ptr << endl;
cout << *ptr << endl;

*ptr = 2.25;

cout << ptr << endl;
cout << *ptr << endl;

// new and delte are always pair together.
delete ptr; // this is a dangling memory. the address no longer belong to my memory? there are diff types of memory errors

// better way is to set it to nullptr. But it's still a problem, you just get more error info

cout << ptr << endl;

```

- memory leak (memory gets fragmented)
- double deallocation
- dangling pointer (os saying you look like virus)
- null pointer exception

- `nullptr` keyword that represents a null pointer constant, indicating that a pointer does not point to any valid object or function. It is a type-safe replacement for NULL or 0, providing better compile-time checking and avoiding ambiguity in overloaded functions
