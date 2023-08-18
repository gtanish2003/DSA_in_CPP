#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

int findPosition(int in[], int inOrderStart, int inOrderEnd, int element, int n)
{
    for (int i = inOrderStart; i <= inOrderEnd; i++)
    {
        if (in[i] == element)
        {
            return i;
        }
    }
    return -1;
}

Node *solve(int in[], int pre[], int &preOrderIndex, int inOrderStart, int inOrderEnd, int n)
{
    // base case
    if (preOrderIndex >= n || inOrderStart > inOrderEnd)
    {
        return NULL;
    }

    int element = pre[preOrderIndex++];
    Node *root = new Node(element);
    int position = findPosition(in, inOrderStart, inOrderEnd, element, n);

    // recursive calls
    root->left = solve(in, pre, preOrderIndex, inOrderStart, position - 1, n);
    root->right = solve(in, pre, preOrderIndex, position + 1, inOrderEnd, n);

    return root;
}
Node *buildTree(int in[], int pre[], int n)
{
    int preOrderIndex = 0;
    Node *ans = solve(in, pre, preOrderIndex, 0, n - 1, n);
    return ans;
}

// what we are doing traversing the inorder aaray everytime to find the position ,so we can replace it with the help of map concept

void createMapping(int in[], map<int, int> &NodeToIndex, int inOrderStart, int inOrderEnd, int n)
{
    for (int i = inOrderStart; i <= inOrderEnd; i++)
    {
        NodeToIndex[in[i]] = i;
    }
}

Node *solve(int in[], int pre[], int &preOrderIndex, int inOrderStart, int inOrderEnd, int n, map<int, int> &NodeToIndex)
{
    // base case
    if (preOrderIndex >= n || inOrderStart > inOrderEnd)
    {
        return NULL;
    }

    int element = pre[preOrderIndex++];
    Node *root = new Node(element);
    int position = NodeToIndex[element];

    // recursive calls
    root->left = solve(in, pre, preOrderIndex, inOrderStart, position - 1, n, NodeToIndex);
    root->right = solve(in, pre, preOrderIndex, position + 1, inOrderEnd, n, NodeToIndex);

    return root;
}
Node *buildTree(int in[], int pre[], int n, int inOrderStart, int inOrderEnd)
{
    int preOrderIndex = 0;
    map<int, int> NodeToIndex;
    createMapping(in, NodeToIndex, inOrderStart, inOrderEnd, n);
    Node *ans = solve(in, pre, preOrderIndex, 0, n - 1, n, NodeToIndex);
    return ans;
}
