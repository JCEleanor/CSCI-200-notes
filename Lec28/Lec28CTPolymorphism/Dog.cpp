#include "Dog.h"
#include <iostream>
using namespace std;

Dog::Dog()
{
    cout << "Creating a Dog" << endl;
}

Dog::~Dog()
{
    cout << "Destroying a Dog" << endl;
}

// bark is a specialized function
// void Dog::bark() const
// {
//     cout << "Woof Woof!" << endl;
// }

void Dog::speak() const
{
    cout << "Woof Woof!" << endl;
}