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
