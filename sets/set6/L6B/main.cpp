#include <iostream>
#include <vector>
#include <string>
#include <random>

#include "Array.hpp"
#include "LinkedList.hpp"

using namespace std;

int main()
{
    Array<int> array;
    LinkedList<int> intLinkedList;
    LinkedList<string> stringLinkedList;

    vector<int> nums = {4, 3, 8, 1, 5, 9, 7, 2, 6};
    vector<string> animals = {"bird", "cat", "dog", "elephant"};

    for (size_t i = 0; i < nums.size(); i++)
    {
        array.insert(array.size(), nums[i]);
        intLinkedList.insert(intLinkedList.size(), nums[i]);
    }

    for (size_t i = 0; i < animals.size(); i++)
    {
        stringLinkedList.insert(stringLinkedList.size(), animals[i]);
    }

    cout << "Sorting an array: " << endl;
    cout << "Initial array: " << array << endl;
    array.sort();
    cout << "Sorted array: " << array << endl;

    cout << "Sorting a Linked List: " << endl;
    cout << "Initial List: " << intLinkedList << endl;
    intLinkedList.sort();
    cout << "Sorted List: " << intLinkedList << endl;

    cout << "Initial List: " << stringLinkedList << endl;
    stringLinkedList.sort();
    cout << "Sorted List: " << stringLinkedList << endl;

    int userInput;
    do
    {
        cout << "Enter 1 for searching in Array; 2 for searching in Linked list: ";
        cin >> userInput;
    } while (userInput != 1 && userInput != 2);

    int n, min, max;
    cout << "Enter how many integers to generate: ";
    cin >> n;
    cout << "Enter the smallest value to generate: ";
    cin >> min;
    cout << "Enter the largest value to generate: ";
    cin >> max;
    cout << endl;

    IList<int> *list = nullptr;
    if (userInput == 1)
    {
        list = new Array<int>();
    }
    else
    {
        list = new LinkedList<int>();
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(min, max);

    for (int i = 0; i < n; i++)
    {
        list->insert(list->size(), dist(gen));
    }

    cout << "Initial list: " << *list << endl;
    list->sort();
    cout << "Sorted list: " << *list << endl;

    int loopCout = 0;
    cout << "How many target values do you wish to search for: ";
    cin >> loopCout;

    if (loopCout > 0)
    {
        for (int i = 0; i < loopCout; i++)
        {
            int target;
            cout << "Enter value to search for: ";
            cin >> target;
            int targetIndex = list->search(target);

            if (targetIndex == -1)
            {
                cout << "Target " << target << " not found" << endl;
            }
            else
            {
                cout << "Target " << target << " found at position " << targetIndex << endl;
            }
        }
    }

    delete list;
    return 0;
}