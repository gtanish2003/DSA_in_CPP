#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

//as we kmpw the property of the bst
// that leftmost elemnt is the min element
// and rightmost element is the max element

int min(Node*root){
    Node*temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp->data;
}


int max(Node*root){
    Node*temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp->data;
}