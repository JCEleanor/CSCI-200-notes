## lvalue vs. rvalue

- lvalue has a memory address
- rvalue is an object that does not represent some identifiable location in memory

- `lvalue`, and `rvalue` might show up in the error messages

## `&`: reference operator

```c++
int var;
var = 5;
int& var2 = var; // var2 is an alias for var (they share the same memory address
var2 = 6; // changes var as well!
```

## Pass by Reference with &

Instead of passing the value of an
argument to the function, pass the
argument’s memory address to the
function

```c++
void add_five(int &x){
    x += 5;
}

int main (){
    int a (4);
    cout << a << endl; //4
    add_five(aa);
    cout << a << endl; // 9
    return 0;
}
```

## PBV, PBR, PBP

```c++
// doesn't change anything other that its local variable
void f1(int x) { x = 3; }
// dereferencing pZ and change the value to 3
void f2(int* pZ) { *pZ = 3; }

int x = 1; z = 1;
f1(x);

// pass the address of z, and inside f2, it change the value of that memory address to 3
f2(&z);

cout << x << " " << z; // x = 1, z = 3
```

```c++
// doesn't change anythig other than the local variable pY
void g2(int *pY) { pY = new int; }

// the parameter is the actual value pY, so it will change the value of the parameter to a new integer
void g2(int **pY) { *pY = new int; }

int *ptr = nullptr;
int *ptr2 = nullptr;

// pass in ptr (which is a pointer)
g2(ptr); // memory leak

// pass in the reference of ptr2, which is a nullptr
g3(&ptr2);

cout << *ptr << " " << *ptr2; // ptr =  dangling pointer, ptr2 = 0?
```

```c++
// doesn't change anything other than its local variable
void f1(int x) { x = 3; }
// change the actual value of the parameter to 4
void f2(int * pZ) { *pZ = 4; }
// change the local variable to a 5, which is a new value on the heap (sketchy) => yes this is a memory leak
void g2(int * pY) { py = new int(5); }

int x = 1, z = 1;
int *ptr = new int(6);
int *ptr2 = new int(7);

f1(x); // x = 1
f1(*ptr); // *ptr = 6

f2(&z); // z = 4
f2(*ptr); // *ptr = 4

g2(&z); // z = 4
g2(ptr2); // ptr2 = 7
```

```c++
// receive a copy of a pointer
void h1(int *pY){
    // successfully delete the original memory becasue the pY holds the actual memory
    delete pY;

    // set the local variable pY to nullptr, but the original pointer remain
    pY = nullptr;

    // this function leaves the original pointer a dangling pointer
}

// receive the memory address of a pointer
void h2(int **ppZ) {
    // go to the address of the parameter, and delete the memory it points to
    delete *ppZ;

    // This accesses the original pointer (p2) and sets it to nullptr
    *ppZ = nullptr;

    // this function safely deletes the memory and cleans up the original pointer by setting it to nullptr
}

int *p1 = new int(5);
int *p2 = new int(7);

h1(p1); // p1 is now a dangling pointer
h2(&p2); // p2 is now a nullptr

// when trying to access the value of a nullptr, there will be seg fault
cout << *p1 << " " << *p2;
```

```c++
void g1(int* pY) { pY = new int; }
void g2(int*& pZ) { pZ = new int; }

int* p1 = nullptr;
int* p2 = nullptr;

g1(p1); // p1 = nullptr (g1 creates memory leak)
g2(p2); // p2 is memory address of int (0)
```

```c++
void h1(int* pY) { delete pY; pY = nullptr; }
// this function will safely delete the pointer
void h1(int*& pZ) { delete pZ; pZ = nullptr; }

int *p1 = new int;
int *p2 = new int;

h1(p1); // free store address
h2(p2); // 0x0 (null pointer)

cout << p1 << " " << p2;
```

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
