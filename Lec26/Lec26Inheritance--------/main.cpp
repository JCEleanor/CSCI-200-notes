#include "Dog.h"
#include "Cat.h"
#include "Animal.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{

    Animal john;
    john.setName("John");
    cout << john.getName() << " says ..." << endl;

    cout << endl;

    // call the parent constructor before calling the child constructor
    Dog odie;
    odie.setName("Odie");
    cout << odie.getName() << " says " << odie.bark() << endl;

    cout << endl;

    Cat garfield;
    garfield.setName("Garfield");
    cout << garfield.getName() << " says " << garfield.meow() << endl;

    cout << endl;
    return 0;
    // for the destructor, first destroy the derived class and then the base class
}