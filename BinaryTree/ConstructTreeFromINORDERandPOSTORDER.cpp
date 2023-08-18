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

void createMapping(int in[], map<int, int> &NodeToIndex, int n)
{
    for (int i = 0; i <= n; i++)
    {
        NodeToIndex[in[i]] = i;
    }
}

Node *solve(int in[], int post[], int &postOrderIndex, int inOrderStart, int inOrderEnd, int n, map<int, int> &NodeToIndex)
{
    // base case
    if (postOrderIndex < 0 || inOrderStart > inOrderEnd)
    {
        return NULL;
    }

    int element = post[postOrderIndex--];
    Node *root = new Node(element);
    int position = NodeToIndex[element];

    // recursive calls
    root->right = solve(in, post, postOrderIndex, position + 1, inOrderEnd, n, NodeToIndex);
    root->left = solve(in, post, postOrderIndex, inOrderStart, position - 1, n, NodeToIndex);

    return root;
}
Node *buildTree(int in[], int post[], int n)
{
    int postOrderIndex = n - 1;
    map<int, int> NodeToIndex;
    createMapping(in, NodeToIndex, n);
    Node *ans = solve(in, post, postOrderIndex, 0, n - 1, n, NodeToIndex);
    return ans;
}
