# Dynamic Array

```c++
int *pDynamicArr = new int [n];

delete[] pDynamicArr; // how does c++ know how much to delete? there are metadata, and c++ keeps track of the size
```

## Pointer Math

Useful for code running in the machine/close to hardware

```c++
int *pDyArr = new int[n];
int *pCurrArrSlot = pDyArr; // *pCurrArrSlot = pCurrArrSlot[0]

for (unsigned int i = 0; i < n ; i ++){
    *pCurrArrSlot = i;
    // move one "integer" over
    pCurrArrSlot ++; // pCurrArrSlot += sizeof(int)
}
```

- Valid behavior
  you can do this, but you probably shouldn't:

```c++
int *pDynArr = new int[n];
pDynArr[i] == *(pDynArr + i);
pDynArr[i] == i[pDynArr];

```

- Invalid behavior

seg fault. unpredictable behavior.

```c++
int staticArr[10];
cout << staticArr[10] << endl; // what happens?

int *pDynArr = new int[10];
cout << pDynArr[10] << endl;   // what happens?
```

## List operation

### Arrays

- **All arrays are pointers; all pointers are arrays**
- element access: Arrays are useful for element access, because it has On of 1 `O(1)` (fast, because arrays are contiguous)
- print/traverse array: `O(n)`
- resize (add/remove) an array: `O(n)`
- search array: `O(n)`
- min/max array: `O(n)`

1. make new array that's one element larger
2. create a loop to copy them one by one to new array
3. delete existing array
4. assign pointer from existimg array to new array

Overall complexity is `O(n)`, so that's what arrays are not good for.

### vector vs array

vectors has all kinds of built in methods (like .size()), so every time if we want pass arrays to a function, we have to also pass in the size of the array.

```c++
void print_array(const int * const P_ARRAY, const int SIZE) {
  for(int i = 0; i < SIZE; i++) {
    cout << P_ARRAY[i] << " ";
  }
}

```

### Vectors

Vectors allocate more memory than needed.

speed vs memory.

- size vs. capacity
-
