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

Node* lca(Node*root,int n1,int n2){
    //base case
    if (root==NULL){
        return NULL;
    }
    if (root->data==n1  ||  root->data==n2){
        return root;
    }
Node*leftAns=lca(root->left,n1,n2);
Node*rightAns=lca(root->right, n1, n2);

if (leftAns!=NULL  &&  rightAns!=NULL){
    return root;
}
else if (leftAns!=NULL &&  rightAns==NULL ){
    return leftAns;

}
else if (rightAns!=NULL   &&   leftAns==NULL){
    return leftAns;
}
else{
    return NULL;
}


}
int main() { 
 

}