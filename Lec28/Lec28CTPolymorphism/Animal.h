#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal
{
public:
    Animal();
    ~Animal();

    std::string getName() const;
    void setName(const std::string &N);

    // virtual-> a child class can overwrite.
    // so virtual is not part of the signature,
    // which mean it does not get included in the cpp file
    // it's just an idicator that the function can't be overwritten
    virtual void speak() const;

private:
    std::string _name;
    double _height;
    double _weight;
};

#endif