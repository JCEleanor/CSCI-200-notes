#include <iostream>
#include "BinarySearchTree.hpp"

using namespace std;

void test_tree(vector<int> values)
{
    BinarySearchTree<int> bst;
    for (int val : values)
    {
        bst.insert(val);
    }

    bst.printInOrder();
    bst.printPreOrder();
    bst.printPostOrder();

    bst.printBreadthOrder();
    bst.printDepthOrder();
    bst.printByLevels();
    bst.height();
}

int main()
{
    // cout << "Tree 1:" << endl;
    test_tree({6, 5, 7, 1, 2, 9, 3});

    // cout << "\nTree 2:" << endl;
    cout << endl;
    test_tree({5, 1, 9, 7, 6, 3, 2});

    /**
     * @brief For a final test, create a third tree as follows:
     * Input and add to the tree in order: 5 2 1 7 9 6 3
     *
     */
    // cout << "\nTree 3:" << endl;
    cout << endl;
    test_tree({5, 2, 1, 7, 9, 6, 3});

    return 0;
}
