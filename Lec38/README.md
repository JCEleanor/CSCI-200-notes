## Linear Search

- guarantee to work on any list
- o(n)

## Binary Search

- list must be sorted
- still follows the **Master Theorem**
- decrease and conquer
- it's tempting to write as a recursive function, but it's better to use a loop

### Recursive Binary Search

### Concern/danger of recursion

```c++
template<typename T>
int binary_search(const List<T>& LIST, const T TARGET, const int START_POS, const int END_POS)
{
  const int MIDDLE_POS = (END_POS - START_POS) / 2 + START_POS;
  if(END_POS < START_POS)
    return -1;
  if(LIST[MIDDLE_POS] == TARGET)
    return MIDDLE_POS;
  if(LIST[MIDDLE_POS] > TARGET)
    return binary_search(LIST, TARGET, START_POS, MIDDLE_POS - 1);
  if(LIST[MIDDLE_POS] < TARGET)
    return binary_search(LIST, TARGET, MIDDLE_POS + 1, END_POS);
}
int targetPos = binary_search(myList, target, 0, myList.size() - 1);

```

The issue is **memory**

**The call stack**
Recursion puts too many stack frames on the call stack. It's possible to have stack overflow when N becomes larger.

- What is the run time? **O(log n)**
- What is the extra memory usage? **O(log n)**
- Is there any backtracking going on?
- post-recursive, pre-recursive work.

Many compilers can optimize tail-recursive functions into a simple loop, making them just as efficient as an iterative solution and preventing stack overflow errors.

### muddy terms

1. post-recursive
2. pre-recursive work
3. tail recursion (no post recursive work is called tail recursion)
4. backtracking

#### key takeaway

use recursive when you have post recursive work (?)

### Iterative Binary Search

- Run Time is still O(log n)
- Extra memory usage is now O(1)
