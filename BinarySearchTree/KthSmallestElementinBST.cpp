#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};


int solve(Node*root,int &i,int k){
    //base case
    if (root == NULL)
    {
        return -1;
    }
    //recursive case
    int left=solve(root->left,i,k);
    if(left!=-1){
        return left;

    }
    i++;
    if (i==k){
        return root->data;

    }

    return solve(root->right,i,k);
}
