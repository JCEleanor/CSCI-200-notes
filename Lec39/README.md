## Two-Dimensional Lists

- could also be 2d linked list :目
-

- pointer artithmatic works in 2d array as well

```c++
int myArray[2][4] = { {4,7,3,2}, {8,1,9,0} };
cout << myArray[1][2] << endl;
```

## Declaring Multidimensional Static Arrays

Have to be known in compile time, so we have to initialize it properly.

### initialize

What is valid what is not?

```c++
int array[2][3] = { {1,2,3}, {4,5,6} };
int array2[2][5] = { {1,2,3}, {4,5} };
int array3[][5] = { {1,2}, {3,4,5,6}, {7} } ; // accepter, c++ will initialize for us
int array4[5][] = { {1,2}, {3,4,5} }; // compiler error
int array5[3][3] = { 1,2,3,4,5,6,7 }
```

you can skip the number of rows (first) but not columns (last)

## Declaring Multidimensional Dynamic Arrays

```c++
int n1, n2;
cout << "Enter size 1: ";
cin >> n1;
T** pArray = new T*[n1];
for(int i = 0; i < n1; i++) {
  cout << "Enter size 2: ";
  cin >> n2; // user can enter different value everytime
  pArray[i] = new T[n2];
}

```

Because user can enter different value everytime, so you can create dynamic arrays with different columns. (Every row element is just a pointer to an array)

### How to clean up 2d dynamic arrays?

## Static v Dynamic

## Higher Dimension Arrays

```c++
// static
int rubiksCube[3][3][3];
// dynamic
int*** pMegaRubiksCube = new int**[n];
for(int i = 0; i < n; i++) {
  pMegaRubiksCube[i] = new int*[n];
  for(int j = 0; j < n; j++) {
    pMegaRubiksCube[i][j] = new int[n];
  }
}
```

## Searching a Grid

for one dimensional lists: linear or binary search (even unsorted-binary search?)

### BFS

Search all neighbors first, then search neighbors of neighbors, and so forth

### DFS

Search one direction first, then backtrack and search a different direction, and so forth
