## Big 3 (memory management for classes)

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
Warehouse::Warehouse() {
  _pBoxen = new vector<Box*>;
}
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
