#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal
{
public:
    Animal();
    // when you have a virtual function, always put virtual in destructor
    // put virtual in destructor so when we destroy a dog, we can also destroy the animal
    virtual ~Animal();
    std::string getName() const;
    void setName(std::string NAME);
    std::string getSpecies() const;
    void sleep() const;

    // abstract declaration
    // animal is now an abstract class
    virtual void speak() const = 0;

protected:
    std::string mSpecies;

private:
    std::string _name;
};

#endif // ANIMAL_H