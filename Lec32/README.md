# Static Arrays

- on the stack
- consecutive byte of memory
- lightweight and fast, but dangerous

```

int scores[3];

scores / scores[0] 0x4f838220 14
scores[1] 0x4f838224 33
scores[2] 0x4f838228 21

```

```c++
// the size of the array has to be known at compile time
// i.e., you can't change it dynamically
// i.e., you can use cin for array size
int store[10];
char omg[3] = {'O', 'M', 'G' };

// 0 is the only optioin to do partially initialize
double temp[365] = {0}; // initialize all value to 0

char myChar[4] = {'A', 00, 00 ,00}; // 0 is null terminator

int z[] = {1, 2, 3}; // size of 3
```

### Finding an Element in Memory

_Why arrays are fast?_

- The array identifier points to the base
  address of the array
- The offset is used to calculate the location of an individual element
- How much to offset? The size of the array
  data type

### Big O notation for runtime to:

- Access an element in an array? **O(1)**
- Traverse an array? **O(n)**
- Search? **O(n)**
- Min / Max? **O(n)**

### Null terminator `\0`

- char `00`
