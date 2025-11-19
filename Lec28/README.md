# polymorphism

- having many forms
- having many behavior

## runtime polymorphism

It allows a single interface (typically a base class or abstract class) to represent multiple underlying forms (derived classes).
In C++, this is achieved through **`virtual` functions** and inheritance. A base class pointer or reference can hold an object of any of its derived classes. When a virtual function is called through that pointer or reference, the program determines at runtime which version of the function to execute based on the actual type of the object being pointed to. This is called dynamic dispatch or late binding.

Also known as **subtype polymorphism, dynamic diapatch, or late binding**

## compile time polymorphism

At compile time, which form to use is known.

### 1. ad hoc polymrphism: overloaded function/operator

```c++
int remainder(int numerator, int denominator) {
   return numerator % denominator;
}
float remainder(float numerator, float denominator) {
   return (numerator / denominator) - (int)(numerator / denominator);
}
// ...
cout << remainder(9, 5) << endl;       // prints 4
cout << remainder(9.0f, 5.0f) << endl; // prints 0.8
```

`reminder` has two forms.

### 2. Parametric polymorphism: template class

```c++
template<typename T>
class LootBox {
public:
  LootBox() { _pLoot = nullptr; }
  void putIn(const T LOOT) {
     if(_pLoot != nullptr) _pLoot = new T(LOOT);
  }
  T takeOut() {
    T loot = *_pLoot;
    delete _pLoot; _pLoot = nullptr;
    return loot;
  }
private:
  T* _pLoot;
};
LootBox< string > wordBox;
wordBox.putIn( "polymorphism" );  // put in a string
LootBox< int > countBox;
countBox.putIn( 2 );              // put in an int
```

`LootBox` has two behaviors

## overriding functions

Derived Class has member function with same
function name and signature as Base Class.

The Derived Class implementation overrides the Base Class implementation and takes precedence. => Bottom up

### `virtual` functions

Virtual Functions created as function pointer

- Entered into VTABLE (virtual table)
- provide a default implementation
- subtype can override parent implementation

#### VTABLE (virtual table)

### `override`

`override` keyword checks that function signatures match
AND parent function is virtual – can be overridden

##### How to call parent function

function hiding

There are two methods:

1. type cast subclass to parent class (treat Dog as Animal)

```c++
((Animal)odie).speak();
```

2. scope resolution

```c++
odie.Animal::speak()
```

### Polymorphism in Action

```c++
void hearAnimal(Animal animal) {
animal.speak();
}
void hearDog(Dog dog) {
dog.speak();
}
// ...
Dog odie;
hearDog(odie);
hearAnimal(odie);
```

### Multiple Inheritance

```c++
class Dog : public Animal, public Pet
```

#### Diamond Problem

get compiler error: ambiguous type

To resolve the issues of multiple inheritance and diamond problem, we can use:

1. type cast

```c++
((Animal)odie).speak();
```

2. scope resolution

```c++
odie.Animal::speak()
```
