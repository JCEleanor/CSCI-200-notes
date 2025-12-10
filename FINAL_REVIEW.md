1. polymorphism / inheritance
   - interface, abstract class
   - header file for parent/child class
2. list / sorting (memorize the sort methods that you can. such as linear or bubble sort)
   - when the questions specify use list, you can use IList, vector (have to remember the methods), or static arrays basically any lists

## 1. struct

```c++
#ifndef POINT_H
#define POINT_H

struct Point {
    double x;
    double y;
};

#endif // POINT_H
```

```c++
double distance (Point x, Point y){
  return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
}

int main()
{
    Point p1 = {1.0, 2.0};
    Point p2 = {4.0, 6.0};

    double dist = distance(p1, p2);

    std::cout << "The distance between the two points is: " << dist << std::endl;

    return 0;
}

```

## 2. Lists

- What are the pros/cons of an Array?
  pros: fast
  cons: size must be known in compile time
- What are the pros/cons of a LinkedList?
  pros: fast for insertion in the front and back
  cons: takes much more memory space (with size of pointer(s) which is typically 8 bytes)
- What is the same about an Array & a LinkedList?

- What is different about an Array & a LinkedList?

  - Array: Elements are stored in a single, contiguous block of memory.
  - LinkedList: Elements (nodes) are stored in non-contiguous memory locations, linked by pointers.

- When should one be used over the other?
  - when you want frequent/quick access and know the size of the array before runtime, use arrays
  - when you need to perform many insertions or deletions, especially at the beginning or in the middle of the list, use Linkedlist
- Consider memory, run time complexity, and other considerations

## 3. Sorting

Given a list (Array or LinkedList), implement one of Selection/Insertion/Bubble Sort to sort the list in ascending order.

### Bubble sort

```c++
// simple bubble sort for a vector of integers
void bubbleSort(std::vector<int>& vec) {
    int n = vec.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (vec[j] > vec[j + 1]) {
                // swap
                int temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
            }
        }
    }
}
```

### Insertion sort [TODO]

### Selection sort [TODO]

## 4. Exceptions

- What is the structure sequence necessary when implementing exception handling?
  `try throw catch`
- What is the role of each component?
  - try: wrap code that might throw errors
  - throw: throw expected errors
  - catch: catch expected or unexpected errors and handle them
- Why should we perform exception handling in our code?
  - to catch error and handle it safely, so our program doesn't crash at runtime
  - better experience

## 5. Fill in the missing pieces of code

```c++
// TODO 2: complete the following function named populate_array
/**
* @brief populates an array by setting each element equal to its index i % MOD_VALUE
* @param arr integer array
* @param SIZE size of array
* @param MOD_VALUE modulus value to apply to each element
 * @return int sum of all element values
 */
int populate_array(int* p_arr, int size, int MOD_VALUE ){
    int result = 0;
    for (int i = 0; i < size; i++){
        p_arr[i] = i % MOD_VALUE;
        result += i % MOD_VALUE;
    }

    return result;
}

// TODO 1: create a static integer array with 100 elements
int intArray[100];

// TODO 3: call populate_array with a modulus value of 21 and store result
int result = populate_array(intArayy, 100, 21);

// TODO 4: print result of TODO 3
cout << result;
```

## 6. From UML to Class

```c++
// NOTE: use `final` or `const` these modifiers correctly
class Book final {
public:
    Book();
    Book(String a, String b, int c);
    String GetAuthor() const;
    String GetTitle() const;
    int GetPublicationYear() const;
private:
    _author: String;
    _title: String;
    _publicationYear: int;
}

class Library final{
public:
    Library();
    Library(const Library&);
    ~Library();
    // copy operator
    Library& operator=(const Library& other);
    Book checkoutBook(string b);
    void returnBook(Book*)
private:
    catelog: IList<Book*>*;
}

```

**because it's `IList` so we can't use `vector`, but we can use any other lists**

## 7. Create the Book

Create the following Book functions:

- Default constructor -> Creates book with following members:
  - The C++ Programming Language
  - Bjarne Stroustrup
  - 1986

```c++
Library::Library(){
    this->_author = "Bjarne Stroustrup";
    this->_title = "The C++ Programming Language";
    this->_publicationYear = 1986;
}

// - Parameterized constructor -> sets each data member
Library::Library(string a, string t, int y){
    this->_author = a;
    this->_title = t;
    this->_publicationYear = y;
}

```

- Getters -> returns each data member

```c++
    String GetAuthor() const{
        return this->_author;
    };
    String GetTitle() const{
        return this->_title
    };
    int GetPublicationYear() const{
        return this->_publicationYear;
    };
```

## 8. Create the Library

Create the following Library functions:

- Default constructor -> Initializes an empty list

```c++
Library::Library(){
    // FIXME:
    this->catelog = new std::list<Book*>();
}
```

- Copy constructor -> Performs a Deep Copy Making New Books

```c++
#include <list>

Library& operator=(const Library& other){
 // copy the pointers
 catelog = new std::list<Book*>(*other.catelog)
}
```

- checkoutBook -> If book with title is in list, removes from list and returns. If title is not in list, returns null pointer

```c++
Book* checkoutBook(std::string title){
    for (auto it = catelog->begin(); it!= catelog->end(); it++){
        if ((it)->getTitle() == title){
            Book* found = *it;
            // FIXME: no such functon in catelog
            catelog->remove(it);
            return found;
        }
    }

    // if not found
    return nullptr;
}
```

- returnBook -> puts book in list

```c++
void returnBook(Book*){
    catelog->push_back(Book);
}
```

## 9. From UML to Class II

the diff between interface and
abstract class (italic but no <<interface>> in the UML), some funcyions contain implementation

```c++
class IQuackBehavior {
public:
    virtual string quack() = 0 ; // default implementation
}

class Quack final : public QuackBehavior {
    string quack() override {
        return "quack";
    }
}

class Mute final : public QuackBehavior {
    string quack() override {
        return "";
    }
}
```

## 10. From UML to Class III

Write the C++ Classes corresponding to the following Duck UML diagrams. Have the Duck constructor call the setQuackBehavior method.

In the style guide, named abstract class starts with `A` and interface starts with `I`

```c++
#include <iostream>
#include <string>

// strategy design pattern omg?
// TODO:

class QuackBehavior {
public:
    virtual std::string quack() = 0;
    virtual ~QuackBehavior() {}
};

class Quack : public QuackBehavior {
public:
    std::string quack() override {
        return "quack";
    }
};

class Mute : public QuackBehavior {
public:
    std::string quack() override {
        return "";
    }
};

class Duck {
protected:
    QuackBehavior* qb;
    virtual void setQuackBehavior() = 0;

public:
    Duck() : qb(nullptr) {

    }

    virtual ~Duck() {
        if (qb) {
            delete qb;
        }
    }

    std::string quack() {
        if (qb) {
            return qb->quack();
        }
        return "Error: No behavior set";
    }
};

class MallardDuck : public Duck {
protected:
    void setQuackBehavior() override {
        qb = new Quack();
    }

public:
    MallardDuck() {
        setQuackBehavior();
    }
};

class DecoyDuck : public Duck {
protected:
    void setQuackBehavior() override {
        qb = new Mute();
    }

public:
    DecoyDuck() {
        setQuackBehavior();
    }
};
```

## 11. The Duck Pond

- Create a list of Ducks with 10 ducks. The odd numbered ducks are decoys, the even numbered ducks are mallards.
- Then iterate through the list and make each quack.
- Cleanup all memory.
- Use runtime polymorphism! => expect to be using `->` (pointers)

```c++
std::vector<Duck*> ducks;
for (int i = 0; i < 10; i ++){
    if (i % 2 == 0){
        // mallards
        ducks.push_back(new MallardDuck());
    }else{
        ducks.push_back(new DecoyDuck());
    }
}

for (size_t i = 0; i < ducks.size(); i++) {
        ducks[i]->performQuack();
}

// Clean up
for (Duck *d in ducks){
    delete d; // call virtual destructor
}

ducks.clear();
```

## 12. 2D Arrays

Create a static 2D Character Array with 5 rows and 6 columns. Initialize each element to a space.

```c++
char charArray[5][6];
for (int i = 0; i < 5; i ++){
    for(int j = 0; j < 6; j++){
        charArray[i][j] = ' ';
    }
}
```

## 13. 2D Arrays II

- Prompt the user to enter the number of rows r and columns c.
- Create a dynamic 2D Array of Books (see #6) called bookCase that has r shelves and c books per shelf.
- Make every book B. Stroustrup’s book.

```c++
std::cout << "Enter rows: ";
std::cin >> r;
std::cout << "Enter columns: ";
std::cin >> c;

Book** bookCase = new Book*[r];

for (int i = 0; i < r; ++i) {
    bookCase[i] = new Book[c];
}

// 3. Make every book B. Stroustrup's book
for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
        bookCase[i][j] = Book("B. Stroustrup", "The C++ Programming Language", 2013);
    }
}

```

## 14. 2D Arrays III

- Prompt the user to enter the number of shelves s and books b.
- Create a dynamic 2D Array of Books (see #6) called `bookCase` that has s shelves and b books per shelf.
- When creating each book, prompt the user for the book information.

```c++
for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {

        string t, a;
        int year;
        cout << "Enter title, author and year: ";
        cin >> t;
        cin >> a;
        cin >> year;
        bookCase[i][j] = Book(t, a, year);
    }
}
```

- Then sort the books on each shelf alphabetically.

```c++
// FIXME:
bool compareBooks(const Book& a, const Book& b) {
    if (a.getTitle() != b.getTitle()) {
        return a.getTitle() < b.getTitle();
    }
}

for (int i = 0; i < r; ++i) {
    // array syntax: sort(start_pointer, end_pointer, comparator)
    std::sort(bookCase[i], bookCase[i] + c, compareBooks);
}

```

## 15. 2D Arrays IV

- After the books are sorted, ask the user for a book name.
  - If it exists, tell the user which shelf the book is on and what position on the shelf it is in.
  - Otherwise, tell the user the book cannot be found.

```c++
// using binary search because it's sorted
int high (r*c) -1;
int low = 0;

while (low <= high){
    int mid = low + (high-low) / 2;
    if (bookCase[currentRow][currentCol].getTitle() == userInput){
        found = true;
        break;
    }else if (bookCase[currentRow][currentCol].getTitle() < userInput) {
        low = mid + 1; // search upper half
    }else if (bookCase[currentRow][currentCol].getTitle() < userInput){
        high = mid - 1 // search lower half
    }
}
```

- What is a good search strategy?
- What is the run time to search the bookcase?
  - Express it in terms of s and b

```
Binary Search Complexity: O(log N)
N = total number of books = s*b
```

## 16. Stack Class

Create a class called `RockCairn` that contains a stack of integers. RockCairn::push() will only push to its stack if
the value to be pushed is smaller than the current top value of the stack. It returns true if the value was pushed, false if not. You can assume Stack & Node are implemented.

```c++
#include <stack>

class RockCairn{
private:
    std::stack<int> rocks;
public:
    bool push(int value){
        if (rocks.empty()){
            rocks.push(value);
        }else{
            if (value < rock.top()){
                rocks.push(value);
                return true;
            }else{
                return false;
            }
        }
    }
}
```

## 17. SOLID

- What are the SOLID Principles?
- What is a scenario that each would be applied to?

1. Single-responsibility Principle (SRP) 2. Open/Closed Principle (OCP) 3. Liskov Substitution Principle (LSP) 4. Interface Segregation Principle (ISP) 5. Dependency Inversion Principle (DIP)

What is a scenario that each would be applied to?

1.  Single-responsibility Principle (SRP): A class should have only one reason to change.

2.  Open/Closed Principle (OCP): Software entities (classes, modules, functions, etc.) should be open for extension, but closed for modification.

3.  Liskov Substitution Principle (LSP): Subtypes must be substitutable for their base types without altering the correctness of the program.

    - Scenario: If Square inherits from Rectangle, ensure that substituting a Square object wherever a Rectangle is expected doesn't break the code (e.g., setHeight/setWidth on a Square might change both dimensions, which might not be expected for a Rectangle).

4.  Interface Segregation Principle (ISP): Clients should not be forced to depend on interfaces they do not use.

    - create smaller interfaces with just necessary data fields.

5.  Dependency Inversion Principle (DIP): Depend upon abstractions, not concretions. High-level modules should not depend on low-level modules; both should depend on abstractions.
