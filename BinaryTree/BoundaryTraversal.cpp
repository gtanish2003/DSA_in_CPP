#include <iostream>
#include <vector>
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


void traversalLeft(Node*root,vector<int>&ans){
      //base case
      if (root==NULL  ||  (root->left==NULL  &&  root->right==NULL)){
        return ;
      }
      ans.push_back(root->data);
      if (root->left){
        traversalLeft(root->left,ans);
      }
      else{
        traversalLeft(root->right,ans);
      }

   
}


void traversalLeaf(Node*root,vector<int>&ans){
     //base case
     if (root==NULL){
        return;
     }
    if (root->left==NULL   &&   root->right==NULL){
        ans.push_back(root->data);
        return;
    }
    traversalLeaf(root->left,ans);
    traversalLeaf(root->right,ans);

}

void traverseRight(Node*root,vector<int>&ans){
    //base case
    if (root==NULL  ||  (root->left==NULL  &&  root->right==NULL)){
        return;
    }
    if (root->right){
        traverseRight(root->right,ans);

    }
    else{
        traverseRight(root->left,ans);

    }
    ans.push_back(root->data);

}
vector<int> boundary(Node*root){
    vector<int>ans;
    if (root==NULL){
        return ans;

    }

    ans.push_back(root->data);

    //left part 
    traversalLeft(root->left,ans);

    //traverse leaf nodes
    traversalLeaf(root->left,ans);
    traversalLeaf(root->right,ans);

    //traverse right part
    traverseRight(root->right,ans);

    return ans;


};
