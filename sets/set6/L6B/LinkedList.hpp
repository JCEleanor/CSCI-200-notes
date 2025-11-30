#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include "List.hpp"

#include <exception>
#include <iostream>
#include <string>

template <typename T>
class LinkedList final : public IList<T>
{
public:
    LinkedList();
    ~LinkedList();

    int size() const override;
    T get(const int POS) const override;
    void set(const int POS, const T VALUE) override;
    void insert(const int POS, const T VALUE) override;
    void remove(const int POS) override;
    T min() const override;
    T max() const override;
    int find(const T VALUE) const override;
    int rfind(const T VALUE) const override;
    /** merge sort */
    void sort() override;
    void insertionSort();

private:
    struct Node
    {
        T value;
        Node *pNext;
        Node *pPrev;
    };

    Node *_pHead;
    Node *_pTail;
    int _size;
};

//---------------------------------------------------------

template <typename T>
LinkedList<T>::LinkedList()
{
    // set size to zero
    _size = 0;

    // set head to be a nullptr
    _pHead = nullptr;

    // set tail to be a nullptr
    _pTail = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    // remove each node in the list
    Node *current = _pHead;
    while (current != nullptr)
    {
        // store the pointer to the next node before deleteing the current one
        Node *next = current->pNext;

        // delete the current node
        delete current;
        current = next;
    }

    // set size to zero
    _size = 0;

    // set head to be a nullptr
    _pHead = nullptr;

    // set tail to be a nullptr
    _pTail = nullptr;
}

template <typename T>
int LinkedList<T>::size() const
{
    return _size;
}

template <typename T>
T LinkedList<T>::get(const int POS) const
{
    // if POS is out of range, throw std::out_of_range exception
    if (POS < 0 || POS >= _size)
    {
        throw std::out_of_range("position out of range in get()");
    }

    // set current node to head
    Node *current = _pHead;

    // advance current node to POS
    for (int i = 0; i < POS; i++)
    {
        current = current->pNext;
    }

    // return value of current node
    return current->value;
}

template <typename T>
void LinkedList<T>::set(const int POS, const T VALUE)
{
    // if POS is out of range, throw std::out_of_range exception
    if (POS < 0 || POS >= _size)
    {
        throw std::out_of_range("position out of range in set()");
    }

    // set current node to head
    Node *current = _pHead;

    // advance current node to POS
    for (int i = 0; i < POS; i++)
    {
        current = current->pNext;
    }

    // set value of current node
    current->value = VALUE;
}

template <typename T>
void LinkedList<T>::insert(const int POS, const T VALUE)
{
    int insertPos = POS;
    // if POS is before zero, clamp to zero
    if (insertPos < 0)
    {
        insertPos = 0;
    }

    // if POS is after size, clamp to size
    if (insertPos > _size)
    {
        insertPos = _size;
    }

    // create pointer to new node
    Node *newNode = new Node();

    // set value to be VALUE
    newNode->value = VALUE;

    // set previous pointer to nullptr
    newNode->pPrev = nullptr;

    // set next pointer to nullptr
    newNode->pNext = nullptr;

    // if list is currently empty
    // set head and tail to new node
    if (_size == 0)
    {
        _pHead = newNode;
        _pTail = newNode;
    }
    else if (insertPos == 0)
    {
        // otherwise
        // if position is before head

        // set new node next to be head
        newNode->pNext = _pHead;
        // set head previous to be new node
        _pHead->pPrev = newNode;
        // set head to be new ndoe
        _pHead = newNode;
    }
    else if (insertPos == _size)
    {
        // else if position is after tail

        // set new node previous to be tail
        newNode->pPrev = _pTail;
        // set tail next to be new node
        _pTail->pNext = newNode;
        // set tail to be new ndoe
        _pTail = newNode;
    }
    else
    {
        // otherwise

        // set current node to head
        Node *current = _pHead;

        // advance current node to pos
        for (int i = 0; i < insertPos; i++)
        {
            // link new node into current list
            current = current->pNext;
        }

        // insert new node to the list
        newNode->pNext = current;
        newNode->pPrev = current->pPrev;

        /**
         * (A) <-----> (Current)
             ^               ^
             \              /
              `--(newNode)--`
         */

        current->pPrev->pNext = newNode;
        current->pPrev = newNode;

        /**
         * (A) <-> (newNode) <-> (Current)
         */
    }
    // increment size
    _size++;
}

template <typename T>
void LinkedList<T>::remove(const int POS)
{
    int removePos = POS;

    // if array is empty, throw std::out_of_range exception
    if (_size == 0)
    {
        throw std::out_of_range("array is empty in remove()");
    }

    // if POS is before zero, clamp to zero
    if (removePos < 0)
    {
        removePos = 0;
    }

    if (removePos >= _size)
    {
        removePos = _size - 1;
    }

    Node *nodeToRemove = nullptr;
    // case 1: if list has only one element
    if (_size == 1)
    {
        // set node to delete to head
        nodeToRemove = _pHead;
        // set head and tail to be nullptr
        _pHead = nullptr;
        _pTail = nullptr;
    }
    // case 2: if deleting the head (first element)
    else if (removePos == 0)
    {
        nodeToRemove = _pHead;

        // advance head to next
        _pHead = _pHead->pNext;
        // set head previous to nullptr
        _pHead->pPrev = nullptr;
    }
    // case 3: deleting tail
    else if (removePos == _size - 1)
    {
        // set node to delete to tail
        nodeToRemove = _pTail;

        // set tail to previous
        _pTail = _pTail->pPrev;
        // set tail next to nullptr
        _pTail->pNext = nullptr;

        // case 4: deleting from the middle
    }
    else
    {
        nodeToRemove = _pHead;
        for (int i = 0; i < removePos; i++)
        {
            nodeToRemove = nodeToRemove->pNext;
        }

        nodeToRemove->pPrev->pNext = nodeToRemove->pNext;
        nodeToRemove->pNext->pPrev = nodeToRemove->pPrev;
    }

    // unlink node to delete
    if (nodeToRemove != nullptr)
    {
        // delete node
        delete nodeToRemove;
    }

    // decrement size
    _size--;
}

template <typename T>
T LinkedList<T>::min() const
{
    // if list is empty, throw std::out_of_range exception
    if (_size == 0)
    {
        throw std::out_of_range("list is empty in min()");
    }

    // find minimum value within list
    T min = _pHead->value;

    Node *current = _pHead->pNext;
    while (current != nullptr)
    {
        if (current->value < min)
        {
            min = current->value;
        }

        current = current->pNext;
    }

    // return min value
    return min;
}

template <typename T>
T LinkedList<T>::max() const
{
    // if list is empty, throw std::out_of_range exception
    if (_size == 0)
    {
        throw std::out_of_range("list is empty in max()");
    }

    // find maxiumum value within list
    T max = _pHead->value;
    Node *current = _pHead->pNext;

    while (current != nullptr)
    {
        if (current->value > max)
        {
            max = current->value;
        }

        current = current->pNext;
    }

    // return max value
    return max;
}

template <typename T>
int LinkedList<T>::find(const T VALUE) const
{
    // search for first occurrence of VALUE
    int foundIndex = 0;

    // hint: start at the beginning and go forward
    Node *current = _pHead;
    while (current != nullptr)
    {
        if (current->value == VALUE)
        {
            // return index of first occurrence if found
            return foundIndex;
        }
        current = current->pNext;
        foundIndex++;
    }

    // otherwise return -1
    return -1;
}

template <typename T>
int LinkedList<T>::rfind(const T VALUE) const
{
    // search for last occurrence of VALUE
    int foundIndex = _size - 1;

    // hint: start at the end and go backward
    Node *current = _pTail;
    while (current != nullptr)
    {
        if (current->value == VALUE)
        {
            // return index of last occurrence if found
            return foundIndex;
        }
        current = current->pPrev;
        foundIndex--;
    }

    // otherwise return -1
    return -1;
}

template <typename T>
void LinkedList<T>::insertionSort()
{
    // base case
    if (_size < 2)
    {
        return;
    }

    Node *current = _pHead->pNext;

    while (current != nullptr)
    {
        T currentValue = current->value;
        Node *currentNode = current;

        // keep comparing current to the previous value
        while (currentNode->pPrev != nullptr && currentNode->pPrev->value > currentValue)
        {
            // shift larger value forward
            currentNode->value = currentNode->pPrev->value;
            currentNode = currentNode->pPrev;
        }
        currentNode->value = currentValue;

        // move to next node
        current = current->pNext;
    }
}

#endif // LINKED_LIST_HPP