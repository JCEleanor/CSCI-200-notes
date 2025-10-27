## Learning outcomes

1.  Diagram the memory associated with pointer and where the values lie (either in the stack or the free store)

2.  Diagram how pass by pointer works with pass by value and pass by reference in functions

3.  cause and solutions to memory leaks, segmentation faults, dangling pointers, null pointer exception and other pointer related errors

## pointers

```c++
double a = 12.0;
double b = 23.0;

// ptr is a pointer pointing to the address of a
// ptr = 12.0, a = 12.0, b = 23.0
double *ptr = &a;

// dereference the value of the ptr to the value of b (but ptr is still pointing to the address of a)
// ptr = 23.0, a = 23.0, b = 23.0
*ptr = b;

// ptr is now pointing to the address of b
ptr = &b;

// dereference the value of ptr to the value of 13
// ptr = 13.0, a = 23.0, b = 13.0
*ptr = 13.0;

cout << a << " " << b;
```

```c++
double a;
double b = 5.0;

// undefined 5.0
cout << a << " " << b;
>>
```

### Dangling Pointer

```c++
// ptr is a pointer to a double
double *ptr = new double;

// memory address of a double
cout << ptr << endl;
// an uninitialized value of a double 0 (or a garbage value)
cout << *ptr << endl;

// now the address is holding the vlaue of 2.25
*ptr = 2.25;

// memory address of a double 2.25 (the address is the same)
cout << ptr << endl;
// 2.25
cout << *ptr << endl;

// deallocate the memory block in the system
// delete does not change the ptr variable.
// ptr still holds the same address, but it's now point to memory you no longer own
// this is call a dangling pointer
delete ptr;

// the same memory address
// but it's now illegal to use it. if try to do *ptr = 5.0 your program would crash
cout << ptr << endl;
```

### Null Pointer Exception

Cause: dereferencing a nullptr

Effect: a seg fault

```c++
// a pointer variable namedd ptr that can point to a double
// initialize to nullptr (invalid memory address) (typically address 0)
// this is a safe way to initialize a pointer if you don't have valid address available
double *ptr = nullptr;

// error! null pointer exception, or a segmentation fault
// try to write the value 22 to an invalid, non-existent memory location
*ptr = 22;

// the program will crash

cout << *ptr;
// it's legal to call delete on a nullptr
delete ptr;
```

You cannot dereference a null pointer and assign a value. For example, this is legal:

```c++
int x = 10;
int *ptr = nullptr;

// now ptr point to x
// the value of ptr changes from 0 to the address of x
ptr = &x;

// change the value of x to 22
*ptr = 22;
```

Segmentation fault is a general error given by the operating system. It means your program tries to access a "segment" of memory that it doesn't own. The OS steps in and shuts your program down to prevent it from corrupting other programs.

### Dangling Pointer

```c++
// a pointer variable namedd ptr that can point to a double
double *ptr = new double;

// dereference the value to 22.0
*ptr = 22;

// deallocate the memory block in the system (free up the memory)
// the ptr variable itself is unchanged. it still holds the same memory address, but the address is no longer valid
delete ptr;

// since ptr is a dangling pointer, it points to a memory block you no longer own
// it results in undefined behavior, which almost always means your program will crash with a seg fault.
cout << *ptr;
```

#### Dangling Pointer Example 2

```c++
int *createNumber(){
    int num = 10;
    return &num; // return the memory address of num
} // 'num' is destroyed as the function ends. Its memory is no longer valid

int main(){
    // ptr now holds the address of the destroyed num
    // ptr is now a dangling pointer
    int *ptr = createNumber();

    // try to access invalid memory
    cout << *ptr << endl;
}
```

#### Dangling Pointer Example 3

```c++
int *ptr = new int;
*ptr = 50;

// correctly free up the memory
delete ptr;

// at this point, ptr is a dangling pointer
// it still holds the address, but you no longer own that memory

// error: try to write to a memory you don't own
*ptr = 100;
```

#### The "Delete and Null" idiom

The safest way to delete a pointer and prevent dangling pointer error is a two-step process:

```c++
// 1. delete the memory
delete ptr;
// 2. set the pointer to nullptr (erase the address)
ptr = nullptr;

```

### Memory Leak

```c++
void foo(){
    // ptr is a pointer pointing to double
    double *ptr = new double;

    // dereference the value to 22.0
    *ptr = 22;

    // print 22.0
    cout << *ptr << endl;
}

int main(){
    // when the function ends, all local variables inside foo are destroyed.
    // the pointer is gone, but the memory on the heap it was pointing to is never freed with `delete`
    // to fix this, you need to add `delete ptr` before the closing bracket
    foo();
    foo();
}
```

You only call `delete` on a pointer that you created using the `new` keyword.

Modern c++ encourages to use smart pointer: `std::unique_ptr`

### Double Deallocation

```c++
double *ptr = new double;
*ptr = 22;

// the ptr variable itself is unchanged. It still holds the address of that memory, but the address is no longer valid
// ptr is now a dangling pointer
delete ptr;

// this is the error.
delete ptr;
```

### No Error

It's legal to delete a nullptr

```c++
double *ptr = new double;

*ptr = 22;
delete ptr;

// clean up the address to 0
ptr = nullptr;
delete ptr;
```

### Common Errors

1. Dereferencing a pointer that doesn't point to anything anymore (seg fault due to dangling pointer)
2. Not returning dynamic memory when done (memory leak)
3. Dereferencing a null pointer (seg fault due to null pointer exception)
4. Using `delete` on a variable not created with `new` (e.g., trying to delete from the stack)
5. Using `delete` on a pointer that's already deallocated

## Pass by Value and Return by Value

What's the output?

```c++
void enter_coordinate(int x, int y){
    cout << "Enter coordinate x & y: ";
    cin >> x >> y;
}

int x = 1; y = 1;
enter_coordinate(x, y); // user enters 4 5
cout << x << " " << y; // x = 1, y = 1 because when the function ends, all the local variables are destroyed
```

```c++
int enter_coordiate_x(){
    int x;
    cout << "Enter coordinate x: ";
    cin >> x;
    return x;
}

int enter_coordiate_y(){
    int y;
    cout << "Enter coordinate y: ";
    cin >> y;
    return y;
}

int x = 1, y = 1;
x = enter_coordiate_x(); // user enters 4
y = enter_coordiate_y(); // user enters 5
cout << x << " " << y; // x = 4, y = 5
```

## Pass by Pointer and Return by Pointer

```c++
void enter_coordinate(int *px, int *py){
    cout << "Enter coordinate x & y: ";
    cin >> *px >> *py;
}

int x = 1, y = 1;
enter_coordinate(&x, &y); // user enters 4 5
cout << x << " " << y; // x = 4, y = 5
```

#### Pass by Pointers v1

```c++
// a copy of the address from px is given to the p_value parameter
// so P_value now also points to the same heap memory as px
void pointer_setter(int * const P_value, const int VALUE){
    // go to the memory address p_value is pointing to, and change the value to VALUE
    *P_value = VALUE;
}

// const int VALUE: you are not allowed to change the value of VALUE variable
// int * const P_value: P_value is a constant pointer to an integer. You cannot change the pointer itself.
// you cannnot do P_value = 1

int main(){
    // allocate a new piece of memory on the heap/free store
    int *px = new int(0);
    pointer_setter(px, 5);
    cout << *px << endl; // print 5
    return 0;

    // possible memory leak according to Gemini because there's no `delete px`
}
```

#### Pass by Pointers v2

```c++
void pointer_setter(int * const P_value, const int VALUE){
    // when the function get called, P_value is set to the address of x
    *P_value = VALUE;
}

int main(){
    // create memory on the stack (a local variable)
    int x = 0;

    // pass the address of x
    pointer_setter(&x, 5);

    cout << *px << endl; // print 5
    return 0;
}
```

### PBV / PBP

```c++
void f1 (int x) { x = 3; }
void f2 (int*pZ) { *pZ = 3; }

int x = 1, z = 1;
f1(x);
f2(&z);
cout << x << " " << z; // x = 1, z = 3

```

```c++
// when g2 gets called, pY is the value of nullptr
// allocate new memory and make the local copy of pY point to it
// the function does not change the actual value of pY, and it also creates memory leak, because the address of new int is lost forever
void g2(int* pY){ pY = new int; }

// ppz holds the memory address address of another pointer
// *ppz -> dereferencing ppz, give the function access to the value of the original pointer variable from main
// this function will change the actual value of ppz
void g3(int** ppZ){ *ppZ = new int }

int *ptr = nullptr;
int *ptr2 = nullptr;

// pass in nullptr
g2(ptr);
// pass in the address of a nullptr
g3(&ptr2);

// since ptr is still nullptr, trying to access its value will thro NPE (seg fault)
cout << *ptr << endl; // no pointer exception
cout << *ptr2 << endl; // 0
```

Memory leaks:

1. the memory allocate in `g2`is lost because its address was never returned (new int)
2. the memory allocate in `g3` is also leaked becasue `delete ptr2` is never called in `main`

```c++
// doesn't change the value of x
void f1(int x) { x = 3; }

// pass in the value of the pointer pz, and dereferencing its value to 4
void f2(int* pz) { *pz = 4; }

// pass in the value of the pointer py, and doesn't change the value of py (bc py is a local copy of the parameter passing in)
void g2(int* py) { py = new int(5); }

int x = 1, z = 1;
int *ptr = new int(6);
int *ptr2 = new int(7);

f1(x); // x = 1
f1(*ptr); // *ptr = 6

// pass the address of z
f2(&z); // z = 4
f2(ptr); // *ptr = 4

// pass the address of z
g2(&z);  // z = 4
g2(ptr2); // *ptr2 = 7
```

```c++
// delete the local copy of pY and set it to nullptr
void h1 (int* pY) {
    // delete doesn't delete the pointer variable; it deletes the memory at the address the pointer is holding

    // the delte keyword must followed by a pointer. Otherwise it will not compile
    delete pY;
    pY = nullptr;
}

// ppZ holds the memory address of the original pointer
// delete the pointer of pZ and set it to nullptr **safely**
void h2 (int** ppZ) { delete *pZ; *pZ = nullptr; }

int *p1 = new int(5);
int *p2 = new int(7);

h1(p1);
h2(&p2);

// p1 is a dangling pointer; it points to memory that has already been freed
cout << *p1 << endl;

// Dereferencing a nullptr is a "null pointer exception" and also causes a segmentation fault
cout << *p2 << endl;
```

Returning a pointer of a stack memory (which is a terrible bug) and return a pointer to a heap memory

```c++
int* f(){
    int localStackVariable = 5;
    return &localStackVariable;
    // the moment the f finish execusion, the local variable is destroyed. The memory of localStackVariable is no longer valid
    // the function return a dangling pointer
}

int* g(){
    // create a variable on the free store
    int *localFreeStorePointer = new int(5); // be care of memory leak
    // return the address of the localFreeStorePointer
    return localFreeStorePointer;
}

int *ptr = f(); // ptr is a dangling pointer
int *ptr2 = g(); // ptr2 holds a valid memory address

// dereferece a dangling pointer
cout << *ptr << endl; // undefined
cout << *ptr2 << endl; // *ptr = 5

// ERROR: You can only call delete on memory that was allocated with new.
delete ptr;
// this successfully delete ptr2
delete ptr2;
```

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
