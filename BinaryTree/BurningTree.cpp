#include <iostream>
#include <vector>
#include <queue>
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

Node *createParentMapping(Node *root, int target, map<Node *, Node *> &nodeToParent)
{
    // this function create mappimg and also return target node
    Node *result = NULL;
    queue<Node *> q;
    q.push(root);
    nodeToParent[root] = NULL;

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        if (front->data == target)
        {
            result = front;
        }
        if (front->left)
        {
            nodeToParent[front->left] = front;
            q.push(front->left);
        }
        if (front->right)
        {
            nodeToParent[front->right] = front;
            q.push(front->right);
        }
    }
    return result;
}

int burnTree(Node *root, map<Node *, Node *> &nodeToParent)
{
    // this function executes the step-3 of our algo
    map<Node *, bool> visited;
    queue<Node *> q;
    q.push(root);
    visited[root] = true;

    int ans = 0;
    while (!q.empty())
    {

        bool flag = 0;

        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            // process neighbouring nodes
            Node *front = q.front();
            q.pop();

            if (front->left && !visited[front->left])
            {
                flag = 1;
                q.push(front->left);
                visited[front->left] = true;
            }
            if (front->right && !visited[front->right])
            {
                flag = 1;
                q.push(front->right);
                visited[front->right] = true;
            }
            if (nodeToParent[front] && !visited[nodeToParent[front]])
            {
                flag = 1;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = true;
            }

            if (flag == 1)
            {
                ans++;
            }
        }
    }
    return ans;
}

int minTime(Node *root, int target)
{
    // algo:
    // step-1.  create nodeToParent mapping
    // step-2.  find target node
    // step-3.  burn the tree in min time
   
    map<Node *, Node *> nodeToParent;
    Node *targetNode = createParentMapping(root, target, nodeToParent);

    int time = burnTree(targetNode, nodeToParent);
    return time;

   
}