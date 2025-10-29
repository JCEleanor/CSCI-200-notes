#include "Cat.h"
#include <iostream>
using namespace std;

Cat::Cat()
{
    cout << "Creating a Cat" << endl;
    setName("Cat");
}

Cat::~Cat()
{
    cout << "Destroying a Cat" << endl;
}

string Cat::meow() const
{
    return "Cat:: Meow Meow!";
}