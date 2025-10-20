## Encapsulation

## Class in C++

- dot operator / memeber access operator
- data memeber
- scope resolution operator

## Procedural VS. OOP

## Imperative/declarative programming

- Imperative: You write code that describes the step-by-step process to achieve a result.

  - Structured programming

    - Procedural programming
    - Object Orirented programming

    Such as Java, C++

- Declarative: You write code that describes the desired result, and the language figures out how to get there.

  - Functional programming

    such as Haskell, LISP (since 1960)

- Many modern languages are multi-paradigm, meaning they support both imperative and declarative styles of programming. For example, you can write imperative code in
  Python, but you can also use functional programming concepts.

## Diff between a class and an object

### Diff btw a class and an object

#### class

- defines a **new data type** or adds functionalities to an existing data type
- a class **encapsulates** attributes (variables) and behaviors (functions)

#### object

- variable/instance of a defined class
- provides values for the data member of a class

- diff btw a class and a struct

## UML class diagram

Classes exhibit `has-a` and `is-a` relationships

#### `is-a` (Inheritance)

```
 Example:

   1    +-----------+
   2    |  Vehicle  |
   3    +-----------+
   4         /_\
   5          |
   6    +-----------+
   7    |    Car    |
   8    +-----------+
```

#### `has-a` (composite & aggregation)

- Composition (filled diamond): A strong "has-a" relationship. The contained object cannot exist without the container. If the container is destroyed, the contained
  object is also destroyed.
  - Example: A Car has an Engine. The Engine is part of the Car and wouldn't exist on its own.
- Aggregation (hollow diamond): A weaker "has-a" relationship. The contained object can exist independently of the container.
  - Example: A Car has a Driver. The Driver can exist without the Car.

```
Example (Composition):

   1    +-----------+           +-----------+
   2    |    Car    |<>--------|  Engine    |
   3    +-----------+   1       +-----------+
   4

```
