# recursion

## unwinding the code stack

## tail recursion

when you have tail recursion, you can do it with a loop. In some compiler, it will get compiled into a for loop.

## Towers of Hanoi

```c++

```

## Solve a problem by solving a smaller instance of the same problem

- Divide-and-conquer (merge sort)
- Decrease-and-conquer (Hanoi)

## Merge Sort

### Pseudocode

```
function mergeSort( List list ) {
  // base case

  // recursive case
    // divide
    // resurse
    // conquer
}

```

#### LinkedList Pseudocode (POP Style)

```c++
template<typename T>
void merge_sort( LinkedList<T>* const P_list  ) {
    // base case
  if(P_list == nullptr
       || P_list->size() <= 1) return; // already sorted
  // divide & split
  LinkedList<T> *pLeft = new LinkedList<T>,
                *pRight = new LinkedList<T>;
  split_list(P_list, pLeft, pRight);
      // P_list now empty, pLeft & pRight hold both halves
  // recurse
  merge_sort(pLeft);
  merge_sort(pRight);
  // conquer & merge
  merge_lists(pLeft, pRight, P_list);
      // P_list now sorted, pLeft & pRight empty
  delete pLeft, pRight;
}

```

#### LinkedList Pseudocode (OOP Style)

```c++
template<typename T>
void LinkedList<T>::mergeSort() {
  // base case
  if(_size <= 1) return; // already sorted

  // divide & split
  LinkedList<T> *pLeft = new LinkedList<T>,
                *pRight = new LinkedList<T>;
  _splitList(pLeft, pRight);
  // callee now empty, pLeft & pRight hold both halves
  // recurse
  pLeft->mergeSort();
  pRight->mergeSort();
  // conquer & merge
  _mergeLists(pLeft, pRight);
      // callee now sorted, pLeft & pRight empty
  delete pLeft, pRight;
}
```

**Becasue we are breaking array into two parts, it takes up more memory space.**

## Naïve Cost Analysis

### Master Theorem

- T(n) = 2T(n/2) + n
  - n/2 -> the split
  - +n -> the merge
- T(1) = 1

If your list is small, it's probably better to use other sorting methods like bubble sort or insertion sort

- O(T) < O(T2) < O(n log n)
