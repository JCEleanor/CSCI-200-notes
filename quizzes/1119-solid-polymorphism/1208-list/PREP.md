## Static Arrays (fixed size)

### Fixed size so compiler can allocate space for it. Size is known at **compile time**

```c++
// create an array called stores to hold 10 integers
int stores[10];

// create an array called omg to hold 3 characters
char omg[3] = {'O', 'M', 'G'}

double cool[2] = {0.2, 1.2};

// compiler assumes an array of size 2
int z = {1, 2};
```

The elements inside `stores` will contain indeterminate (garabage) values. Accessing or printing these uninitialized values results in undefined behavior.

### Initialize an Array

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

## Array Time complexity

| Operation            | Time Complexity | Notes                                           |
| :------------------- | :-------------- | :---------------------------------------------- |
| Access (by index)    | O(1)            | Direct memory calculation.                      |
| Search (unsorted)    | O(N)            | Must check each element in the worst case.      |
| Insertion / Deletion | O(N)            | Requires shifting subsequent elements.          |
| **Space Complexity** | **O(N)**        | **Memory is allocated upfront for N elements.** |

## The Special Case of Character Arrays (C-Style Strings)

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

- Array Size: The total number of characters the array can physically hold. This is fixed when you declare it. char myCString[10]; has a size of 10.
- String Length: The number of characters before the null terminator \0. This can be less than the array size.

Example:

```c++
 // Array SIZE is 10
 char myCString[10] = "Hi!";

 // String LENGTH is 3 (for 'H', 'i', '!')
 // The data stored is {'H', 'i', '!', '\0', ?, ?, ?, ?, ?, ?}
 // The actual memory used by the string is 4 bytes (including '\0')
```

Rule: The size of your character array must always be at least one character greater than the length of the string you want to store to make room for the \0.

**Trying to access data beyond the null terminator (but within the array's bounds) is unpredictable, and accessing beyond the array's bounds is an error.**
