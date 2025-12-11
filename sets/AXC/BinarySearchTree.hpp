#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <iomanip>

template <typename T>
class BinarySearchTree
{
private:
    struct TreeNode
    {
        T value;
        TreeNode *left = nullptr;
        TreeNode *right = nullptr;
        TreeNode(const T &val) : value(val) {}
    };

    TreeNode *root;
    int mSize;

    void destroyTree(TreeNode *node)
    {
        if (node)
        {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

    /**
     * @brief perform deep copy
     *
     * @param node
     * @return TreeNode*
     */
    TreeNode *copyTree(TreeNode *node)
    {
        if (!node)
        {
            return nullptr;
        }
        TreeNode *newNode = new TreeNode(node->value);
        newNode->left = copyTree(node->left);
        newNode->right = copyTree(node->right);
        return newNode;
    }

    void recursiveInsert(TreeNode *&node, const T &val)
    {
        if (!node)
        {
            node = new TreeNode(val);
            mSize++;
        }
        else if (val < node->value)
        {
            recursiveInsert(node->left, val);
        }
        else
        {
            recursiveInsert(node->right, val);
        }
    }

    void recursicePrintInOrder(TreeNode *node) const
    {
        if (node)
        {
            recursicePrintInOrder(node->left);
            std::cout << node->value << " ";
            recursicePrintInOrder(node->right);
        }
    }

    void recursivePrintPreOrder(TreeNode *node) const
    {
        if (node)
        {
            std::cout << node->value << " ";
            recursivePrintPreOrder(node->left);
            recursivePrintPreOrder(node->right);
        }
    }

    void recursivePrintPostOrder(TreeNode *node) const
    {
        if (node)
        {
            recursivePrintPostOrder(node->left);
            recursivePrintPostOrder(node->right);
            std::cout << node->value << " ";
        }
    }

    /**
     * @brief : Print the number of levels in the tree.
     *
     * @param node
     * @return int
     */
    int recursiveHeight(TreeNode *node) const
    {
        if (!node)
        {
            return 0;
        }
        return 1 + std::max(recursiveHeight(node->left), recursiveHeight(node->right));
    }

    /**
     * @brief Print the tree level by level, each on their own line.
     *
     * @param node
     */
    void printByLevels(TreeNode *node) const
    {
        if (!node)
        {
            return;
        }

        std::queue<TreeNode *> q;
        q.push(node);
        int level = 1;
        while (!q.empty())
        {
            int levelSize = static_cast<int>(q.size());
            std::cout << "Level " << level++ << ": ";
            for (int i = 0; i < levelSize; ++i)
            {
                TreeNode *current = q.front();
                q.pop();
                std::cout << current->value << " ";
                if (current->left)
                {

                    q.push(current->left);
                }
                if (current->right)
                {
                    q.push(current->right);
                }
            }
            std::cout << std::endl;
        }
    }

public:
    BinarySearchTree()
    {
        root = nullptr;
        mSize = 0;
    }

    BinarySearchTree(const BinarySearchTree &other)
    {
        root = copyTree(other.root);
        mSize = other.mSize;
    }

    ~BinarySearchTree()
    {
        destroyTree(root);
        root = nullptr;
        mSize = 0;
    }

    BinarySearchTree &operator=(const BinarySearchTree &other)
    {
        // step 1: chcek for self assignment
        if (this == &other)
        {
            return *this;
        }

        // step 2: deallocate old data `this` owns
        destroyTree(root);

        // step 3: deep copy
        root = copyTree(other.root);
        mSize = other.mSize;

        // step 4: return the reference to allow chained assignemnt
        return *this;
    }

    /**
     * @brief  inserts a node for the given VAL.
     * If VAL is less than the root, recursively attempt to add to the left subtree.
     * If VAL is greater or equal to the root, recursively attempt to add to the right subtree. Increments the size by one.
     * (Note: We are not going to be implementing the balanced binary search tree.)
     *
     * @param val
     */
    void insert(const T &val)
    {
        recursiveInsert(root, val);
    }

    /**
     * @brief returns the current total number of nodes in the tree
     *
     * @return int
     */
    int size() const
    {
        return mSize;
    }

    /**
     * @brief Recursively print the left subtree,
     * then print the current node, then recursively print the right subtree.
     *
     */
    void printInOrder() const
    {
        std::cout << "In Order:      ";
        recursicePrintInOrder(root);
        std::cout << std::endl;
    }

    /**
     * @brief Print the current node, then recursively print the left subtree,
     * then recursively print the right subtree.
     *
     */
    void printPreOrder() const
    {
        std::cout << "Pre Order:     ";
        recursivePrintPreOrder(root);
        std::cout << std::endl;
    }

    /**
     * @brief Recursively print the left subtree,
     * then recursively print the right subtree, then print the current node.
     *
     */
    void printPostOrder() const
    {
        std::cout << "Post Order:    ";
        recursivePrintPostOrder(root);
        std::cout << std::endl;
    }

    /**
     * @brief Print the tree level by level using a breadth first search.
     *
     */
    void printBreadthOrder() const
    {
        std::cout << "Bredth Order: ";
        if (!root)
        {
            std::cout << std::endl;
            return;
        }

        // use queue for bfs
        std::queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            // step 1: get the first value from the queue
            TreeNode *current = q.front();
            q.pop();
            std::cout << current->value << " ";

            if (current->left)
            {
                q.push(current->left);
            }

            if (current->right)
            {
                q.push(current->right);
            }
        }
        std::cout << std::endl;
    }

    void printDepthOrder() const
    {
        std::cout << "Depth Order:   ";
        if (!root)
        {
            std::cout << std::endl;
            return;
        }

        // use stack for depth first search, FIFO
        std::stack<TreeNode *> stack;
        stack.push(root);
        while (!stack.empty())
        {
            TreeNode *current = stack.top();
            stack.pop();
            std::cout << current->value << " ";
            if (current->right)
            {
                stack.push(current->right);
            }
            if (current->left)
            {
                stack.push(current->left);
            }
        }
        std::cout << std::endl;
    }

    void printByLevels() const
    {
        std::cout << "By Levels:" << std::endl;
        this->printByLevels(root);
    }

    void height() const
    {
        std::cout << "Height: " << recursiveHeight(root) << std::endl;
    }
};

#endif // BINARY_SEARCH_TREE_HPP