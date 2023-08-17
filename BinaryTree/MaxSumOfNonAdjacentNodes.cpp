#include<iostream>
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


pair<int,int>solve(Node*root){
    //base case
    if (root==NULL){
        pair<int,int>p=make_pair(0,0);
        return p;
    }
    pair<int,int>leftAns=solve(root->left);
    pair<int,int>rightAns=solve(root->right);

    pair<int,int>res;
    //iska matlab max sum including root node
    res.first=root->data+leftAns.second+rightAns.second;
    //ab vo sum jo exclude krke lana h
    res.second=max(leftAns.first,leftAns.second)+max(rightAns.first,rightAns.second);
    return res;

}

int getMaxSum(Node*root){
    pair<int,int>ans=solve(root);
    return max(ans.first,ans.second);
}