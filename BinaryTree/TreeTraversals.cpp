#include <iostream>
#include <queue>
#include <stack>
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

Node *buildTree(Node *root)
{
    cout << "Enter the data" << endl;
    int data;
    cin >> data;

    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter the data to be insert in left of" << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data to be insert in right of" << data << endl;
    root->right = buildTree(root->right);

    return root;
}

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

void RecursiveInorderTraversal(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // recursion
    RecursiveInorderTraversal(root->left);
    cout << root->data;
    RecursiveInorderTraversal(root->right);
}

void RecursivePreOrderTraversal(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // recursion
    cout << root->data;
    RecursivePreOrderTraversal(root->left);
    RecursivePreOrderTraversal(root->right);
}

void RecursivePostOrderTraversal(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // recursion

    RecursivePostOrderTraversal(root->left);
    RecursivePostOrderTraversal(root->right);
    cout << root->data;
}

void IterativeInorderTaversal(Node *root)
{
    stack<Node *> s;
    Node*current=root;
    while (current != NULL && !s.empty())
    {
        if (current != NULL)
        {
            s.push(current);
            current = current->left;
        }
        else
        {
            cout << current->data << " ";
            current = s.top();
            s.pop();
            current = current->right;
        }
    }
}

void IterativePreOrder(Node *root)
{
    stack<Node *> s;
    while (root != NULL && !s.empty())
    {
        if (root != NULL)
        {
            cout << root->data << " ";
            s.push(root);
            root = root->left;
        }
        else
        {

            root = s.top();
            s.pop();
            root = root->right;
        }
    }
}

void IterativePostOrder(Node *root)
{
    stack<Node *> s;
    while (root != NULL && !s.empty())
    {
        if (root != NULL)
        {

            s.push(root);
            root = root->left;
        }
        else
        {

            root = s.top();
            s.pop();
            root = root->right;
            cout << root->data << " ";
        }
    }
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);

    cout<<"Output after level order traversal"<<endl;
    LevelOrderTraversal(root);

    cout<<"Output after recursive inorder traversal"<<endl;
    RecursiveInorderTraversal(root);

    cout<<"Output after iterative postorder traversal"<<endl;
    IterativePostOrder(root);


}
