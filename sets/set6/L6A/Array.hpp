#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "List.hpp"

#include <exception>
#include <iostream>
#include <string>

template<typename T>
class Array final : public IList<T> {
public:
    Array();
    ~Array();

    int size() const override;
    T get(const int POS) const override;
    void set(const int POS, const T VALUE) override;
    void insert(const int POS, const T VALUE) override;
    void remove(const int POS) override;
    T min() const override;
    T max() const override;
    int find(const T VALUE) const override;
    int rfind(const T VALUE) const override;

private:
    int _size;
    T* _pArray;
};

//---------------------------------------------------------

template<typename T>
Array<T>::Array() {
    // set size to zero

    // set array to be a nullptr
    
}

template<typename T>
Array<T>::~Array() {
    // deallocate current array
    
}

template<typename T>
int Array<T>::size() const { 
    return _size;
}

template<typename T>
T Array<T>::get(const int POS) const {
    // if POS is out of range, throw std::out_of_range exception
    
    // return value at POS within array
    return T();
}

template<typename T>
void Array<T>::set(const int POS, const T VALUE) {
    // if POS is out of range, throw std::out_of_range exception
    
    // set VALUE at POS within array    

}

template<typename T>
void Array<T>::insert(const int POS, const T VALUE) {
    // if POS is before zero, clamp to zero

    // if POS is after size, clamp to size

    // create new array of size + 1

    // copy elements 0 to POS from old array to new array

    // set element at POS in new array to VALUE

    // copy elements POS to size from old array to new array

    // delete old array

    // set old array to be new array

    // increment size

}

template<typename T>
void Array<T>::remove(const int POS) {
    // if array is empty, throw std::out_of_range exception

    // if POS is before zero, clamp to zero

    // if POS is after size, clamp to size

    // create new array of size - 1

    // copy elements from 0 to POS from old array to  new array

    // copy elements from POS+1 to size from old array to new array

    // delete old array

    // set old array to be new array

    // decrement size

}

template<typename T>
T Array<T>::min() const {
    // if array is empty, throw std::out_of_range exception
    
    // find minimum value within array
    
    // return min value
    return T();
}

template<typename T>
T Array<T>::max() const {
    // if array is empty, throw std::out_of_range exception
    
    // find maximum value within array
    
    // return max value
    return T();
}

template<typename T>
int Array<T>::find(const T VALUE) const {
    // search for first occurrence of VALUE
    // hint: start at the beginning and go forward
    
    // return index of first occurrence if found
    
    // otherwise return -1
    return -1;
}

template<typename T>
int Array<T>::rfind(const T VALUE) const {
    // search for last occurrence of VALUE
    // hint: start at the end and go backward

    // return index of last occurrence if found

    // otherwise return -1
    return -1;
}

#endif//ARRAY_HPP