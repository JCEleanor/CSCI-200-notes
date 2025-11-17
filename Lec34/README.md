# `struct`

create own custom data type.

```c++
struct StructureName {
    dataType variableName;
    dataType variableName;
    // all data members are public by default
};

int main (){
    structureName myStructureVar;
}
```

## Chain `struct` together

## `struct` v `class`

`struct` and `class` are identical except:

- class: everything by default is `private`.
- struct: everything by default is `public`.

### When to use what?

By convention:

- data only: struct
- data and functions: class

# Linked Lists

## Singly Linked List

Array: [1, 2, 3]
Linked list: [1] -> [2] -> [3]

In Linked list, we'll have a Node where we have a value and a pointer to the next value. The Node is a `struct`.

A "recursive" data strcuture:

1. defined in terms of itself, contains reference to itself
2. composed of instane of the same data structure

```c++
struct Node {
    int value;
  Node* pNext;
};
```

## Linked Lists Operations

### 1. Make a Node

```c++
struct Node {
    int value;
  Node* pNext;
};

Node* pHead, pTail;

// step 1: create new Node on the free store
Node *pNew = new Node();
// step 2: set value
pNew->value = 1;
// step 3: set pNext to nullptr
pNew->pNext = nullptr; // nothing after the list right now
```

### 2. Add a Node to the front

- Linked lists are good at adding/removing arrays

```c++
// create a new node
Node *pNew2 = new Node();
pNew2->value = 2;
pNew2->pNext = pHead;
pHead = pNew2;
```

### 3. Get node i

### 4. Print/Traverse/Find/Min/Max/Size the List

### 5. Print backwards (O(n^2))

## Doublely Linked List (L6A)

```c++
struct Node {
  int value;
  Node* pNext;
  Node* pPrev;
};
```

## Linked List Operations

### 1. Make a Node

```c++
Node* pHead, pTail;

```

### 2. Add/Remove a Node to the front

### 3. Add/Remove a Node to the back

### 4. Get Node i
