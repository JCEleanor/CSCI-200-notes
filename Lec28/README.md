# polymorphism (compile time polymorphism)

## runtime polymorphism

## compile time polymorphism

### overloaded function

ad hoc

### template class

## overridden functions

same name, same datatype

### `virtual`

Virtual Functions created as function pointer

- Entered into VTABLE (virtual table)

### `override`

Use virtual keyword in parent class and override keyword in subclasses

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
