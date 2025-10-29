#include "Dog.h"
#include <iostream>
using namespace std;

Dog::Dog()
{
    cout << "Creating a Dog" << endl;
    setName("Dog");
}

// we have a destroctor here but we only have primitive data type(which got destroied) but it's here for polymorphysim
Dog::~Dog()
{
    cout << "Destroying a Dog" << endl;
}

string Dog::bark() const
{
    return "Dog:: Woof Woof!";
}
