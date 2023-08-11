#include<iostream>
#include<queue>
#include<vector>
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


void RecursiveInorderTraversal(Node*root,int &count)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // recursion
    RecursiveInorderTraversal(root->left,count);

    //leaf node
    if (root->left  == NULL  &&  root->right ==  NULL){
        count++;
    }
  
    RecursiveInorderTraversal(root->right,count);
}

int NoOfLeafNodes(Node*root){
    int cnt=0;
     RecursiveInorderTraversal(root,cnt);
    return cnt;
}