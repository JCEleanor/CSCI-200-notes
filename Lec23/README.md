# Templates

```c++
// by convention, name the generic type T. (but you could name it however you want)
template<typename T>
```

## hpp file

it contains implementation and definition

## some tutorials say to do

don't do it like p.21. it will create an empty object file (compiling-wise, it works thou)

## Template classes

note: you shouls implement big three for the code in p.25 (but for simplicity, it's not there)

## File Extensions

### `*.h`: header file

- contains only declaration
- is not compiled on its own

### `*.c`: compilable file

- compiled on its own and linked into executable

### `*.pp`: implementation file

- contain definitions

### `*.hpp`: header implementation file

- contain declaration and corresponding definitions
- is not compiled on its own, still a header file

### `*.cpp`: compile implementation file

- contains function definitions
- is compiled
