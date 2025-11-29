# CSCI 200 - Fall 2025

## Foundational Programming Concepts & Design

This lab is due by Monday, December 08, 2025, Before Class.

As with all labs you may, and are encouraged, to pair program a solution to this lab. If you choose to pair program a solution, be sure that you individually understand how to generate the correct solution.

Jump To: · [Rubric](#rubric) · [Submission](#submission) ·

## Sorting Instructions

For this lab, add to your abstract `List` class a purely virtual `void sort()` method. This function will need to be implemented as both `Array::sort()` and `LinkedList::sort()`. Both of these implementations will perform the recursive Merge Sort algorithm.

To test your implementations, perform the following steps for each `List` implementation:

- Create a list of integers
- Populate the list with the values in order: 4 3 8 1 5 9 7 2 6
- Print the list forwards (prints 4 3 8 1 5 9 7 2 6)
- Sort the list
- Print the list forwards (prints 1 2 3 4 5 6 7 8 9)

To assist with the debugging of the recursive steps, have each function call print out the contents of the left and right lists after splitting. Additionally, print out the contents of the resultant merged list each function call.

You are encouraged to test your sorting with other list contents to verify its correctness (such as a list of strings).

An example run of the program may be:

```
Sorting an array:
Initial array: 4 3 8 1 5 9 7 2 6
Left: 4 3 8 1 5
Right: 9 7 2 6
Initial array: 4 3 8 1 5
Left: 4 3 8
Right: 1 5
Initial array: 4 3 8
Left: 4 3
Right: 8
Initial array: 4 3
Left: 4
Right: 3
Merged: 3 4
Merged: 3 4 8
Initial array: 1 5
Left: 1
Right: 5
Merged: 1 5
Merged: 1 3 4 5 8
Initial array: 9 7 2 6
Left: 9 7
Right: 2 6
Initial array: 9 7
Left: 9
Right: 7
Merged: 7 9
Initial array: 2 6
Left: 2
Right: 6
Merged: 2 6
Merged: 2 6 7 9
Merged: 1 2 3 4 5 6 7 8 9
```

When it's verified the sorting algorithm is operating correctly, remove the debugging outputs to clean up the generated output. Now the example run would be similar to below:

```
Sorting an array:
Initial array: 4 3 8 1 5 9 7 2 6
Sorted array: 1 2 3 4 5 6 7 8 9

Sorting a Linked List:
Initial list: 4 3 8 1 5 9 7 2 6
Sorted list: 1 2 3 4 5 6 7 8 9

Sorting a Linked List:
Initial list: dog cat bird elephant
Sorted list: bird cat dog elephant
```

## Searching Instructions

Next, add to your abstract `List` class a purely virtual `int search(T)` method. This function will need to be implemented as both `Array::search(T)` and `LinkedList::search(T)`. The Array implementation will use binary search while the LinkedList implementation will use linear search.

To test your implementations, perform the following steps:

- Ask the user which list implementation to use
- Ask the user how many integers to enter `n`
- Ask the user for the smallest value to generate `min`
- Ask the user for the largest value to generate `max`
- Create a list of `n` integers
- Assign each element a random value within the range provided `[min, max]`
- Print the list forwards
- Sort the list ascending
- Print the list forwards
- Ask the user how many target values they wish to search for
- For each target value entered by the user, perform a search to find the target. If the target is found, then print the position the target is first found at. If the target is not found, then print -1.

For example, if our sorted array contains `1 3 3 3 5` and the user is searching for

- `1`, then the value is found at position 0
- `3`, then the value is found at position 2
- `5`, then the value is found at position 4
- `2`, then the value is "found" at position -1

For example, if our sorted linked list contains `1 3 3 3 5` and the user is searching for

- `1`, then the value is found at position 0
- `3`, then the value is found at position 1
- `5`, then the value is found at position 4
- `2`, then the value is "found" at position -1

## Grading Rubric

Your submission will be graded according to the following rubric:

| Points | Requirement Description                                        |
| ------ | -------------------------------------------------------------- |
| 0.70   | Fully meets specifications                                     |
| 0.15   | Submitted correctly by Monday, December 08, 2025, Before Class |
| 0.15   |                                                                |

## Lab Submission

Always, always, ALWAYS update the header comments at the top of your `main.cpp` file. And if you ever get stuck, remember that there is LOTS of [help](../resources/help.html) available.

Zip together your `main.cpp`, `Makefile`, `List.hpp`, `Array.hpp`, `LinkedList.hpp` file(s) and name the zip file `L6B_USERNAME.zip`. Upload this zip file to Canvas under L6B.

This lab is due by Monday, December 08, 2025, Before Class.

As with all labs you may, and are encouraged, to pair program a solution to this lab. If you choose to pair program a solution, be sure that you individually understand how to generate the correct solution.
