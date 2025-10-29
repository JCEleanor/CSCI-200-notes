# Big 3 (memory management for classes)

```c++
// Warehouse.h
class Warehouse {
public:
  Warehouse();
  void storeInBox(const int SIZE);
  Box* getBox(const size_t POS);
  size_t getNumberBoxes() const;
private:
  std::vector<Box*>* _pBoxen;
};

// Warehouse.cpp
#include "Warehouse.h"

Warehouse::Warehouse() {
  _pBoxen = new vector<Box*>;
}

void Warehouse::storeInBox(const int SIZE){
  _pBoxen->push_back(new Box(SIZE));
}

Box* Warehouse::getBox(const size_t POS){
  return _pBoxen->at(POS);
}

size_t getNumberBoxes() const {
  return _pBoxen->size();
}

// main.cpp
Warehouse *pWarehouseH = new Warehouse;
pWarehouseH->storeInBox(4)l
cout << pWarehouseH << endl; // print address 0x4321l???
cout << *pWarehouseH << endl; // error! invalid operands to binary expression
```

## Operator overloading

To fix the above error, **overload the stream insertion operator (`<<`) for the `Warehouse` class**.

Inside `main.cpp` or `Warehouse.cpp`:

```c++
#include <iostream>
#include "Warehouse.h"

std::ostream& operator<<(std::ostream& os, const Warehouse& WH){
  // 'os' is the stream (like cout)
  // WH is the object to pinrt
  os <<  "Warehouse has " << WH.getNumberBoxes() << " boxes";

  // it's required to return the stream 'os'
  return os;
}
```

Break it down:

- `std::ostream&`: this function return a reference to an `ostream` object
- `operator <<`: this is the special name c++ recognize. It tells the compiler: it's a new behavior for the `<<` operator. The syntax operator<symbol> is c++'s built in mechanism for operator overloading.
- `return os`: this allow chaining.

Another example:

Overloading `[]` to replace `getBox()`:

```c++
// inside Warehouse.cpp
Box* Warehouse::operator[](const size_t POS){
  return _pBoxen->at(POS);
}

// inside main.cpp
// old way
Box* box1 = pWarehouseH->getBox(0);

// new way
Box* box2 = (*pWarehouseH)[0];
```

1. copy assignment operator
   - delete the callee content
     - (p.33: loop thru the vector, delete each box or delete the vecror)
   - deep copy from OTHER to this
     - loop thru OTHER, and add this to this.vector
2. copy constructor (copy the exact same logic from step 2 of copy assignment)
3. destructor (handle cleanup) (copy the exact same logic from step 1 of copy assignment) (`~Warehouse()`)

- when the destructor will be called?
- object lifecycle

### operator overloading

function overloading (ftn with same name, different prarams)

```c++
// free function (typically in header file)
// Warehouse.h
std::ostream& operator<<(
    std::ostream&, const Warehouse&
);

// Warehouse.cpp
std::ostream& operator<< (std::ostream& os, const Warehouse& WH){
  os << "Warehouse has " << WH.getNumberBoxes() << " boxes";
  return os;
}
```

```c++
Warehouse& Warehouse::operator=(const Warehouse& OTHER){
  // guard against self assignment
  if (this == &OTHER) return *this;

  return *this
}
```

## Assignment, deep, shallow copy

- shallow copy point to the same memory address
- deep copy having two different memory addresses, but exactly same content

##
