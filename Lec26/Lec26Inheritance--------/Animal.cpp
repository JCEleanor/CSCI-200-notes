#include "Animal.h"
#include <iostream>

using namespace std;

Animal::Animal()
{
    cout << "Creating an animal" << endl;
    _name = "Animal";
    _height = 1;
    _weight = 1;
}

Animal::~Animal()
{
    cout << "Destroying an animal" << endl;
}

std::string Animal::getName() const
{
    return _name;
}

void Animal::setName(const std::string &N)
{
    _name = N;
    return;
}