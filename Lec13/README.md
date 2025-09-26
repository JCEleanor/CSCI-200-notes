- `lvalue`, and `rvalue` might show up in the error messages

- reference cannot be changed. pointer can change. In general, reference is notationally easier

- pass by reference => when you don't want to deal with pointer (memory address)

```c++
// pass by reference, is it SOLID?
void add_five( int& x ) {
    // x is just another name for the same memory spot in disk

    x += 5;
}
```

```c++
void h1(int* pY) { delete pY; pY = nullptr; }
void h2(int** ppZ) { delete *ppZ; *ppZ = nullptr; }
...
int *p1 = new int(5);
int *p2 = new int(7);

h1(p1);
// pY and p1 point out to the same memory spot
// but pY is deleted, and nothing will happen in p1.

h2(&p2);
// padding addres of p2,
// ppZ is a pointer pointing at p2
cout << *p1 << " "; // what happens? -> dangling pointer
cout << *p2; // what happens? -> null pointer exception

```

```c++
void g1(int* pY) { pY = new int; }
void g2(int*& pZ) { pZ = new int; }
...
int* p1 = nullptr;
int* p2 = nullptr;
g1(p1); // what does p1 point to? -> nullptr and memory leak
g2(p2); // what does p2 point to?

```
