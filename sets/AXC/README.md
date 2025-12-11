# CSCI 200 - Fall 2025

## Foundational Programming Concepts & Design

## AXC - Binary Search Trees

→This assignment is due by Thursday, December 11, 2025, 11:59 PM.←  
→ As with all assignments, this must be an individual effort and cannot be pair programmed. Any debugging assistance must follow the course collaboration policy and be cited in the comment header block for the assignment.←

Jump To: · [Rubric](#rubric) · [Submission](#submit) ·

---

### The BinarySearchTree Class

---

We are going to now make a new templated class called `BinarySearchTree`. This will necessitate creating a new struct for a `TreeNode` to store the left and right pointers as appropriate.

The `BinarySearchTree` class needs to have the following public methods created:

- `BinarySearchTree()` - Constructor that sets the root pointer to be null and set the size to be zero
- `BinarySearchTree(const BinarySearchTree& OTHER)` - Copy Constructor that performs a deep copy of the other tree
- `~BinarySearchTree()` - Destructor that deallocates the entire tree, sets the root pointer to be null, sets the size to be zero
- `BinarySearchTree& operator=(const BinarySearchTree& OTHER)` - Copy Assignment Operator that deallocates the existent tree (if any) then performs a deep copy of the other tree
- `void insert(const T VAL)` - inserts a node for the given `VAL`. If `VAL` is less than the root, recursively attempt to add to the left subtree. If `VAL` is greater or equal to the root, recursively attempt to add to the right subtree. Increments the size by one. (_Note: We are not going to be implementing the balanced binary search tree._)
- `int size() const` - returns the current total number of nodes in the tree

---

### Tree Traversal

---

We'll expand our Tree class by adding the following public methods:

- `printInOrder()`: Recursively print the left subtree, then print the current node, then recursively print the right subtree.
- `printPreOrder()`: Print the current node, then recursively print the left subtree, then recursively print the right subtree.
- `printPostOrder()`: Recursively print the left subtree, then recursively print the right subtree, then print the current node.

To test your implementation, perform in `main.cpp` the following steps in order:

1. Create a BinarySearchTree of integers
2. Prompt the user for how many integers to enter
3. Input and add to the tree in order: 6 5 7 1 2 9 3
4. printInOrder()
5. printPreOrder()
6. printPostOrder()

Your program should display:

```
In Order:   1 2 3 5 6 7 9
Pre Order:  6 5 1 2 3 7 9
Post Order: 3 2 1 5 9 7 6
```

A second run of the program with the following inputs:

1. Input and add to the tree in order: 5 1 9 7 6 3 2

Would display:

```
In Order:   1 2 3 5 6 7 9
Pre Order:  5 1 3 2 9 7 6
Post Order: 2 3 1 6 7 9 5
```

We'll now add two more ways to traverse the tree:

- `printBreadthOrder()`: Print the tree level by level using a breadth first search.
- `printDepthOrder()`: Print the tree branch by branch using a depth first search.

Your first tree should display:

```
In Order:      1 2 3 5 6 7 9
Pre Order:     6 5 1 2 3 7 9
Post Order:    3 2 1 5 9 7 6
Breadth Order: 6 5 7 1 9 2 3
Depth Order:   6 5 1 2 3 7 9
```

Your second tree should display:

```
In Order:      1 2 3 5 6 7 9
Pre Order:     5 1 3 2 9 7 6
Post Order:    2 3 1 6 7 9 5
Breadth Order: 5 1 9 3 7 2 6
Depth Order:   5 1 3 2 9 7 6
```

We'll now add a way to pretty print by level:

- `printByLevels()`: Print the tree level by level, each on their own line.

Your first tree should display:

```
In Order:      1 2 3 5 6 7 9
Pre Order:     6 5 1 2 3 7 9
Post Order:    3 2 1 5 9 7 6
Breadth Order: 6 5 7 1 9 2 3
Depth Order:   6 5 1 2 3 7 9
By Levels:
Level 1: 6
Level 2: 5 7
Level 3: 1 9
Level 4: 2
Level 5: 3
```

Your second tree should display:

```
In Order:      1 2 3 5 6 7 9
Pre Order:     5 1 3 2 9 7 6
Post Order:    2 3 1 6 7 9 5
Breadth Order: 5 1 9 3 7 2 6
Depth Order:   5 1 3 2 9 7 6
By Levels:
Level 1: 5
Level 2: 1 9
Level 3: 3 7
Level 4: 2 6
```

Finally, add a method to print the height, or number of levels, of the tree.

- `height()`: Print the number of levels in the tree.

Your first tree should display:

```
In Order:      1 2 3 5 6 7 9
Pre Order:     6 5 1 2 3 7 9
Post Order:    3 2 1 5 9 7 6
Breadth Order: 6 5 7 1 9 2 3
Depth Order:   6 5 1 2 3 7 9
By Levels:
Level 1: 6
Level 2: 5 7
Level 3: 1 9
Level 4: 2
Level 5: 3
Height: 5
```

Your second tree should display:

```
In Order:      1 2 3 5 6 7 9
Pre Order:     5 1 3 2 9 7 6
Post Order:    2 3 1 6 7 9 5
Breadth Order: 5 1 9 3 7 2 6
Depth Order:   5 1 3 2 9 7 6
By Levels:
Level 1: 5
Level 2: 1 9
Level 3: 3 7
Level 4: 2 6
Height: 4
```

For a final test, create a third tree as follows:

1. Input and add to the tree in order: 5 2 1 7 9 6 3

This tree will print:

```
In Order:      1 2 3 5 6 7 9
Pre Order:     5 2 1 3 7 6 9
Post Order:    1 3 2 6 9 7 5
Breadth Order: 5 2 7 1 3 6 9
Depth Order:   5 2 1 3 7 6 9
By Levels:
Level 1: 5
Level 2: 2 7
Level 3: 1 3 6 9
Height: 3
```

---

### Grading Rubric

---

Your submission will be graded according to the following rubric:

| Points | Requirement Description                                                                                |
| ------ | ------------------------------------------------------------------------------------------------------ |
| 0.5    | Submitted correctly by Thursday, December 11, 2025, 11:59 PM                                           |
| 0.5    | Project builds without errors nor warnings.                                                            |
| 2.0    | [Best Practices](../resources/bestPractices.html) and [Style Guide](../resources/style.html) followed. |
| 0.5    | Program follows specified user I/O flow.                                                               |
| 0.5    | Public and private tests successfully passed.                                                          |
| 2.0    | Fully meets specifications.                                                                            |
| 6.00   | Total Points                                                                                           |

---

### Submission

---

Always, **always**, **ALWAYS** update the header comments at the top of your main.cpp file. And if you ever get stuck, remember that there is LOTS of [help](../resources/help.html) available.

Zip together your `BinarySearchTree.hpp, main.cpp, Makefile` files and name the zip file `AXC_USERNAME.zip`. Upload this zip file to Canvas under AXC.

→This assignment is due by Thursday, December 11, 2025, 11:59 PM.←  
→ As with all assignments, this must be an individual effort and cannot be pair programmed. Any debugging assistance must follow the course collaboration policy and be cited in the comment header block for the assignment.←

Last Updated: 08/20/25 12:53  
Any questions, comments, corrections, or request for use please contact jpaone {at} mines {dot} edu.  
Copyright © 2022-2025 Jeffrey R. Paone
