base type (parent type)
derived type (child type)

sub class
superclass

### public inheritance

In C++, when you inherit from a class without specifying an access modifier, it defaults to `private` inheritance.

```c++
// private inheritance
// if not specify, default to private
// all public member of Polygon become private in Quadrilateral
class Quadrilateral : Polygon
{
public:
    Quadrilateral();
};

// public inheritance
class Quadrilateral : public Polygon
{
public:
    Quadrilateral();
};

```
