#include <iostream>
#include <queue>
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

Node *insertIntoBST(Node *&root, int d)
{
    // base case
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }

    if (d > root->data)
    {
        // right part me insert krna h
        root->right = insertIntoBST(root->right, d);
    }
    else
    {
        // left part me insert krna h
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}

void takeinput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

// level order taversal se traverse kr lenge

void LevelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // Purana wala traversal complete ho chuka h
            cout << endl;
            if (!q.empty())
            {
                // Queue still has some child nodes
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{
    Node *root = NULL;
    cout << "Enter the data to create BST" << endl;
    takeinput(root);
    cout << "Printing the BST is:" << endl;
    LevelOrderTraversal(root);
}
