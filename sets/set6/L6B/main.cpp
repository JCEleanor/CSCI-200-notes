#include <iostream>
#include <vector>

#include "Array.hpp"
#include "LinkedList.hpp"

using namespace std;

int main()
{
    Array<int> array;
    LinkedList<int> intLinkedList;
    vector<int> nums = {4, 3, 8, 1, 5, 9, 7, 2, 6};
    for (size_t i = 0; i < nums.size(); i++)
    {
        array.insert(array.size(), nums[i]);
        intLinkedList.insert(intLinkedList.size(), nums[i]);
    }

    cout << "Sorting an array: " << endl;
    cout << "Initial array: " << array << endl;
    array.sort();
    cout << "Sorted array: " << array << endl;

    cout << "Sorting a Linked List: " << endl;
    cout << "Initial List: " << intLinkedList << endl;
    intLinkedList.sort();
    cout << "Sorted List: " << intLinkedList << endl;

    return 0;
}