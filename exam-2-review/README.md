### 12.

```c++
// DiningSet.h

#ifndef DININGSET_H
#define DININGSET_H

// 1. Include the header files for the classes we are using.
// The DiningSet "has a" Chair and "has a" Table.
#include "Chair.h"
#include "Table.h"

// 2. Class Definition
class DiningSet {

public:
    DiningSet();
    double getPrice() const;
    void setSold(bool sold);
    bool isSold() const;

private:
    Chair _chair1;
    Chair _chair2;
    Table _table;
    bool _isSold;
};

#endif // DININGSET_H
```

## 13.

13. Composition
    (a) Write the function implementation of the Chair’s default constructor. Use 10.0 for the price and 1 for the height, width, and depth.
    (b) Write the implementation of getPrice() for your DiningSet class. getPrice() is equal to the sum of the table and chairs price

```c++
// a
class Chair { // in Chair.h
public:
  Chair(): Chair(1, 1, 1, 10.0);
  Chair( int, int, int, double );
  // all getters and setters
private:
  int _height, _width, _depth;
  double _price;
};
// b
double DiningSet::getPrice() const {
    return _chair1.getPrice() + _chair2.getPrice() + _table.getPrice();
}
```
