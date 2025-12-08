# Static Arrays (fixed size in the **stack** `int[10] intArr;`)

### Fixed size so compiler can allocate space for it. Size is known at **compile time**

```c++
// create an array called stores to hold 10 integers
// contain garbage value
int stores[10];
// initialize all values to 0
static int arr[10];

// create an array called omg to hold 3 characters
char omg[3] = {'O', 'M', 'G'}

double cool[2] = {0.2, 1.2};

// compiler assumes an array of size 2
int z = {1, 2};
```

### Initialize a Static Array

Elements of a static array are only guaranteed to be zero-initialized if:

1.  It's a **global array**.
2.  It's declared with the `static` keyword (e.g., `static int stores[10];`).
3.  It's **explicitly initialized**, even partially (e.g., int stores[10] = {}; or int stores[10] = {1, 2};).

### Arrays in Memory: memory addresses are contiguous, so accessing element is FAST

For integers (size is 4 bytes / 32 bits)

| identifier / name[offset] | memory address | value |
| :------------------------ | :------------- | :---- |
|                           | `0x4f83821c`   |       |
| `scores` / `scores[0]`    | `0x4f838220`   | `14`  |
| `scores[1]`               | `0x4f838224`   | `33`  |
| `scores[2]`               | `0x4f838228`   | `21`  |
|                           | `0x4f83822c`   |       |
|                           | `0x4f838230`   |       |

##### Reacll datatype

Data Type Sizes (Recall for Pointer Arithmetic)

| Data Type     | Typical Size (bytes)          | Notes                                                  |
| :------------ | :---------------------------- | :----------------------------------------------------- |
| `bool`        | 1                             |                                                        |
| `char`        | 1                             |                                                        |
| `short`       | 2                             |                                                        |
| `int`         | 4                             | Most common on modern systems                          |
| `long`        | 4 or 8                        | Often 8 on 64-bit systems                              |
| `long long`   | 8                             |                                                        |
| `float`       | 4                             | Single-precision floating-point                        |
| `double`      | 8                             | Double-precision floating-point                        |
| `long double` | 8, 12, or 16                  | Extended-precision floating-point                      |
| **Pointers**  | 4 (on 32-bit) / 8 (on 64-bit) | Size of memory address, crucial for pointer arithmetic |

### Array Time complexity

| Operation            | Time Complexity | Notes                                           |
| :------------------- | :-------------- | :---------------------------------------------- |
| Access (by index)    | O(1)            | Direct memory calculation.                      |
| Search (unsorted)    | O(N)            | Must check each element in the worst case.      |
| Insertion / Deletion | O(N)            | Requires shifting subsequent elements.          |
| **Space Complexity** | **O(N)**        | **Memory is allocated upfront for N elements.** |

### The Special Case of Character Arrays (C-Style Strings)

1. The Core Concept: The Null Terminator (\0)

This is the most important rule and the reason for all other special behaviors.

- A C-style string is an array of characters that ends with a special character called the null terminator, which is written as `\0`.
- When you initialize a character array with a string literal (text in double-quotes), the compiler automatically adds \0 to the end.

For example

```c++

char myCString[15] = "I Love C++!";
```

Even though "I Love C++!" is 12 characters long, the compiler stores 13 characters in the array: 'I', ' ', 'L', 'o', 'v', 'e', ' ', 'C', '+', '+', '!', '\0'.

2. Consequence #1: Special I/O Behavior

Because of the null terminator, you don't need a loop to print a C-style string.

- Normal Arrays: For an int array, you have to loop through and print each element one by one (slide 33).
- C-style Strings: cout knows to print characters one after another until it finds the \0 null terminator. Then it stops automatically.

This is why this code works directly: `cout << myCString;`

3. Consequence #2: Dedicated Library Functions (<cstring>)

The null terminator also allows a whole library of special functions to work on C-style strings without needing to know the array's declared size. You just need to `#include <cstring>`.

- `strlen()` or `strnlen()`: Calculates the length of the string by counting characters **until it hits `\0`**, i.e., not include null terminator
  - `strnlen` is safer as in it prevents reading beyond the bounds of a buffer (unlike `strlen`, if `\0` is beyond allocated memory, it will continuously read past the end og the buffer, leading to undefined behavior, such as a crash or security vulnerability)
- `strcpy()` or `strncpy()`: Copies a string by copying characters until `\0` is found.
- And others like `strcat()` (concatenate) and `strcmp()` (compare).

4. Critical Distinction: Array Size vs. String Length

This is a common point of confusion that slides 39 & 40 try to explain.

- Array Size: The total number of characters the array can physically hold. This is fixed when you declare it. `char myCString[10];` has a size of 10.
- String Length: The number of characters before the null terminator `\0`. This can be less than the array size.

Example:

```c++
 // Array SIZE is 10
 char myCString[10] = "Hi!";

 // String LENGTH is 3 (for 'H', 'i', '!')
 // The data stored is {'H', 'i', '!', '\0', ?, ?, ?, ?, ?, ?}
 // The actual memory used by the string is 4 bytes (including '\0')
```

Rule: The size of your character array must always be at least one character greater than the length of the string you want to store to make room for the `\0`.

**Trying to access data beyond the null terminator (but within the array's bounds) is unpredictable, and accessing beyond the array's bounds is an error.**

## Dynamic Arrays (size determined at runtime in the **heap** `new int* intArr[];`)

Dynamic arrays live in the free store (heap). We can request a block of memory at runtime, but we are responsible for managing this memory.

### Initialization / Deallocation of a Dynamic Array

##### Recall

```c++
int *pNumCars = new int;       // *pNumCars initialized to 0 (on this system)
int *pNumCars2 = new int(5);   // *pNumCars2 initialized to 5
```

- `new int;` asks the system for enough memory on the heap to store one integer. It returns a pointer (a memory address) to that location, which is stored in `pNumCars`. The value at that address might be zero or garbage, depending on the system.
- `new int(5);` does the same but also initializes the integer at that memory location with the value 5.

```c++
int size;
cout << "Enter array size: ";
cin >> size;

int* p_dynamicArray = new int[size]; // return the pointer of the first element (**Arrays are pointers**)

cout << "*p_dynamicArr: " << *p_dynamicArr << endl; // *p_dynamicArr: 0
cout << "&p_dynamicArr: " << &p_dynamicArr << endl; // &p_dynamicArr: 0x30a1c0c20
cout << "p_dynamicArr: " << p_dynamicArr << endl;   // p_dynamicArr: 0x7fee03f06140

delete[] p_dynamicArray;

// recall: use `delete obj` for single objects
int* p = new int(5);
delete p;
```

### Pointer Math

- Syntatic sugar: `p_dynamicArr[i]` is understood by the compiler as `*(p_dynamicArr + i)`

The compiler translates it into `_(p_dynamicArr + i)`, which means: "start at the base address `p_dynamicArr`, move forward `i` elements, and
then dereference the pointer `*` to get the value at that location.

```c++
  int *pDynamicArr = new int[10];
  int *pCurrentArraySlot = pDynamicArr; // pointing to the same location as pDynamicArr (the start of the array)
  // *pCurrentArraySlot = pCurrentArraySlot[0];

  for (size_t i = 0; i < 10; i++)
  {
    cout << pCurrentArraySlot << endl; // contiguous
    // dereferences the pointer (accesses the memory location it points to) and assigns the value of i to that location.
    *pCurrentArraySlot = static_cast<int>(i);
    pCurrentArraySlot++; // pCurrentArraySlot += sizeof(int)
  }
```

### Invalid Array Access

Array bounds rules apply to both static and dynamic arrays.

```c++
int staticArr[10];
cout << staticArr[10] << endl;

int \*pDynArr = new int[10];
cout << pDynArr[10] << endl;
```

Code Explanation:

- In both cases, an array of size 10 has valid indices from 0 to 9.
- Accessing element 10 is an out-of-bounds access for both the static and dynamic array.
- This results in undefined behavior. The program might crash, print a garbage value, or appear to work by corrupting other
  memory. It is always a bug.

### Resize a Dynamic Array

The 4-Step "Resize" Algorithm:

1.  Make New: Allocate a new, larger dynamic array on the heap.
2.  Copy: Copy all the elements from the old array to the new array, one by one. **EXPENSIVE**
3.  Delete Old: Deallocate the memory used by the old array using delete[].
4.  Re-assign Pointer: Change the original pointer to point to the new array.

```c++
double *pNewArray = new double[n+1];
for (size_t i = 0; i < n; i++){
    pNewArray[i] = pOldArr[i];
}

delete[] pOldArr; // free up the memory on the heap
pOldArr = pNewArray;
```

This is an expensive **O(N)** operation because of the copy step.

### Vector

A cleaner way to resize the array is to use `std::vector`.

- `std::vector` is a wrapper around a dynamic array. It uses a **dynamic array** behind the scenes but manages it for you, making it much safer and easier.

```c++
vector<unsigned int> vec;
cout << vec.size() << " " << vec.capacity() << endl;
for(unsigned int i = 0; i < 129; i++) {
    vec.push_back(i);
    cout << vec.size() << " " << vec.capacity() << endl;
}
```

Example output:

```
0 0
1 1
2 2
3 4
4 4
5 8
6 8
7 8
8 8
9 16
10 16
11 16
12 16
13 16
14 16
15 16
16 16
17 32
18 32
19 32
...
```

Code Explanation:

- This code snippet demonstrates the concepts of size (how many elements are in use) and capacity (how much memory is actually
  allocated).
- As you `push_back` elements, the size increases by one each time.
- However, the capacity does not. It stays the same for a while and then suddenly jumps to a much larger number (e.g., it might go
  from 64 to 128). This jump corresponds to the vector performing the expensive 4-step resize algorithm internally.
- The point: By allocating memory in large chunks, the expensive resize operation happens much less often, making additions much
  faster on average (**amortized O(1) time**).
  - `Amortized O(1)` means that on average, the operation is very fast (O(1) or constant time), even if it is sometimes very slow. The
    cost of the slow operations is "spread out" over many fast operations.
- This is the "speed vs. memory" trade-off.

## Summary

### Static Array

A basic, fixed-size array built into the C++ language.

- Declaration: int arr[10];
- Memory Location: The Stack. Memory is allocated at compile-time.
- Memory Management: Automatic. The memory is automatically freed when the array goes out of scope (e.g., when the function it was
  created in ends). No new or delete.
- Size: Fixed at compile time. The size 10 cannot be changed while the program is running.
- Resizing: Not possible.
- Best Use Case: When you know the exact, small, and unchanging number of elements you need while you are writing the code.

Pros:

- Very fast allocation.
- No risk of memory leaks.

Cons:

- Inflexible size.
- Can cause a "stack overflow" error if you try to make it too large.

### Dynamic Array (raw pointer)

An array that you manually create on the heap using pointers.

- Declaration: int\* arr = new int[10];
- Memory Location: The Heap (Free Store). Memory is allocated at runtime.
- Memory Management: Manual. You are required to allocate it with new[] and free it with delete[]. Forgetting delete[] causes a
  memory leak.
- Size: Fixed at runtime. The size can be a variable when created, but once allocated, that block of memory does not change size.
- Resizing: Manual and expensive. You must perform the 4-step algorithm: (1) allocate a new, larger array, (2) copy old elements,
  (3) delete the old array, (4) point your pointer to the new array.
- Best Use Case: Very rare in modern C++. Mostly for learning how dynamic memory works or when interfacing with C-style libraries
  that require you to manage memory yourself.

Pros:

- Size can be determined at runtime.
- Allows for very large arrays that would not fit on the stack.

Cons:

- Dangerous and error-prone. You are responsible for all memory management. It's easy to forget delete[] (memory leak) or delete
  it too early (dangling pointer).
- Inconvenient to resize.

### std::vector

A C++ Standard Library container that provides a safe, convenient, and powerful dynamic array. This is what you should normally
use.

- Declaration: std::vector<int> vec; or std::vector<int> vec(10);
- Memory Location: The actual data is stored on the Heap (just like a raw dynamic array).
- Memory Management: Automatic (RAII). The vector object automatically allocates memory with new[] when it's created (or when it
  grows) and automatically frees it with delete[] when the vector goes out of scope.
  - RAII (Resource Acquisition Is Initialization) is a C++ programming idiom that ties a resource's lifetime (like memory, file handles, network sockets) to an object's lifetime, ensuring automatic acquisition in the constructor and safe, automatic release in the destructor,
- Size: Truly dynamic. The vector grows and shrinks as you add (push_back) or remove (pop_back) elements.
- Resizing: Automatic. When you push_back and the vector is full, it automatically performs the resize algorithm for you, often
  doubling the capacity to make future additions fast (Amortized O(1)).
- Best Use Case: The default choice for any list/sequence of elements in modern C++.

Pros:

- Safe: Manages its own memory, preventing memory leaks. Can provide bounds-checking with .at().
- Convenient: Has many useful member functions like .push_back(), .pop_back(), .size(), .capacity(), etc.
- Efficient: Performance is excellent and highly optimized.

Cons:

- Has a very small amount of overhead compared to a raw array (for storing its size and capacity), but this is almost never a
  concern.

### Summary Table

| Feature          | Static Array          | Dynamic Array (raw pointer)       | `std::vector`                                            |
| :--------------- | :-------------------- | :-------------------------------- | :------------------------------------------------------- |
| **Memory**       | Stack                 | Heap                              | Heap                                                     |
| **Management**   | Automatic             | **Manual** (`new[]`/`delete[]`)   | **Automatic** (RAII)                                     |
| **Size**         | Fixed at compile-time | Fixed at runtime                  | **Dynamic** (grows/shrinks)                              |
| **Resizing**     | Impossible            | Manual, complex, and slow (O(N))  | **Automatic** and efficient (Amortized O(1) `push_back`) |
| **When to use?** | Small, fixed data     | Rarely; for learning or C interop | **Almost always; the default choice**                    |

# Struct and Class

The only difference is for struct all members are `public` while for class all are `private` by default

# Linked List

Instead of 1 n-element array, chain together n 1-element arrays.

## Singly Linked List

```c++
struct Node {
  int value;
  Node* pNext; // a recursive data structure because it contains a pointer to its own type
}
```

## Doubly Linked List

```c++
struct Node {
  int value;
  Node* pNext;
  Node* pPre; // allow traversing backward just as easily as traversing forward
}
```

### Doubly Linked List Operation

#### Add a Ndoe to the Front

#### Traverse a List Forward

#### Traverse a List Backward

#### Remove a Node from the Front

#### Get Node i

#### Add a Node to the Back

#### Remove a Node to the Back

#### Add a Node to the Middle

#### Remove a Node from the Middle

### Data Structure Complexity

```
  ┌──────────────────┬─────────────────────────────────┬───────────────────────────────┬───────────────────────────────┐
  │ Operation        │ Array                           │ Singly-Linked List            │ Doubly-Linked List            │
  ├──────────────────┼─────────────────────────────────┼───────────────────────────────┼───────────────────────────────┤
  │ Element Access   │ O(1)                            │ O(N)                          │ O(N)                          │
  │ Traversal (Fwd)  │ O(N)                            │ O(N)                          │ O(N)                          │
  │ Traversal (Back) │ O(N)                            │ O(N^2)                        │ O(N)                          │
  │ Add/Del (Front)  │ O(N)                            │ O(1)                          │ O(1)                          │
  │ Add/Del (Middle) │ O(N)                            │ O(N)                          │ O(N)                          │
  │ Add (Back)       │ O(N) or Amortized O(1) (vector) │ O(1) (if tail pointer exists) │ O(1) (if tail pointer exists) │
  │ Delete (Back)    │ O(1)                            │ O(N)                          │ O(1) (if tail pointer exists) │
  │ Memory Space     │ N * sizeof(T)                   │ N * (sizeof(T) + 8)           │ N * (sizeof(T) + 16)          │
  └──────────────────┴─────────────────────────────────┴───────────────────────────────┴───────────────────────────────┘

  (Assuming 64-bit system where pointers are 8 bytes)
```
