#ifndef DOG_H
#define DOG_H

#include "Animal.h"
#include <string>

class Dog : public Animal
{
public:
    Dog();
    ~Dog();

    void bark() const;
    // override means provide a different implementation,
    // so it's not included in cpp
    void speak() const override;

private:
};
#endif