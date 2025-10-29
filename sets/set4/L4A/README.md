Your task is to override the Big 3 on the Warehouse class. Each should do as follows:

Copy Constructor - deep copy the other Warehouse: allocate a new vector and allocate & insert new Boxes into the vector
Copy Assignment Operator - deep copy the other Warehouse: deallocate all boxes within the vector, allocate & insert new Boxes into the vector
Destructor - deallocate all boxes within the vector, deallocate the vector
Hints
You should first implement the destructor to ensure your deallocation works on its own. This will initially result in a runtime error with the function calls due to the default copy that occurs.

Next, implement the copy constructor to resolve the runtime error and make Warehouse D work.

Finally, implement the copy assignment operator to correct Warehouse C.

When working with the Big 3, consider the abstractions of each process:

```c++
CopyConstructor(OTHER) {
  deepCopy(OTHER);
}

CopyAssignmentOperator(OTHER) {
  deallocate(this);
  deepCopy(OTHER);
}

Destructor() {
  deallocate(this);
}
```
