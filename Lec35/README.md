# Exception

- These error messages might differ from windows and Mac.

## Standard Exceptions

For this course, we will use `out of range` exception.

```c++
T get(const T * const P_ARRAY, const int SIZE, const int POS) {
  if(POS >= 0 && POS < SIZE) {
    return P_ARRAY[POS];
  } else {
    string msg = "invalid access at pos " + to_string(POS) + " for size " + to_string(SIZE);
    throw std::out_of_range(msg);
  }
}
```

Back in the day people create their own custom exceptions. (which are inherited from `std::exception`) Nowaways, people just use standard exception.

## Exception Handling

`try` and `catch`

```c++
try {
  // statements that would throw an exception
} catch (ExceptionType1 e) {
} catch (ExceptionType2 e) {
} catch (...) { // generic catch anything that doesn’t match above
}
```

`...` does not get used very much. It's a syntax that catches the rest of the exceptions.

### Exception vs Seg Fault

seg fault => when the OS capture the error, and your program crashes abruptly

```c++
emptyVec[5] = 5;   // seg fault
cout << emptyVec[-4] << endl; // seg fault => when the OS capture the error, and your program crashes abruptly
emptyVec.at(5) = 5;  // exception std::out_of_range vector
cout << emptyVec.at(-4) << endl; // exception std::out_of_range vecto
```
