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

bool searchBST(Node*root,int x){
    //base case
    if (root==NULL){
        return false;
    }
    if (root->data==x){
        return true;
    }

    //recursive case
    if (root->data > x){
        //left part me search krna h
        return searchBST(root->left,x);
    }
    else{
        //right part me search krna h
        return searchBST(root->right,x);
    }
}
//Above solution is not optimized 
//Time complexity is O(h) where h is the height of the tree
//Space complexity is O(h) where h is the height of the tree


// So here comes the optimized solution,using the iterative approach

bool searchInBST(Node*root,int x){
    Node*temp=root;
    while(temp!=NULL){
        if (temp->data == x){
            return true;
        }
        if (temp->data > x){
            temp=temp->left;
        }
        else{
            temp=temp->right;
        }
    }
    return false;
}

