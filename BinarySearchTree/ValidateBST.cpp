#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

bool IsBST(Node *root, int min, int max)
{
    // BASE CASE
    if (root == NULL)
    {
        return true;
    }

    // RECURSIVE CASE
    if (root->data >= min && root->data <= max)
    {
        bool leftBST = IsBST(root->left, min, root->data);
        bool rightBST = IsBST(root->right, root->data, max);
        return leftBST && rightBST;
    }
    else
    {
        return false;
    }
}

bool validateBST(Node *root)
{
    return IsBST(root, INT_MIN, INT_MAX);
}