#include <iostream>
#include <vector>

#include "Array.hpp"
#include "LinkedList.hpp"

using namespace std;

int main()
{
    /**
     * @brief
     *
     * Create a list of integers
Populate the list with the values in order: 4 3 8 1 5 9 7 2 6
Print the list forwards (prints 4 3 8 1 5 9 7 2 6)
Sort the list
Print the list forwards (prints 1 2 3 4 5 6 7 8 9)
     *
     */
    Array<int> array;
    vector<int> nums = {4, 3, 8, 1, 5, 9, 7, 2, 6};
    for (size_t i = 0; i < nums.size(); i++)
    {
        array.insert(array.size(), nums[i]);
    }

    cout << "Initial array: " << array << endl;
}